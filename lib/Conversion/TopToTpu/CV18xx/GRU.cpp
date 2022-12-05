//===----------------------------------------------------------------------===//
//
// Copyright (c) 2020-2030 by Sophgo Technologies Inc. All rights reserved.
//
// Licensed under the Apache License v2.0.
// See http://www.apache.org/licenses/LICENSE-2.0 for license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "tpu_mlir/Conversion/TopToTpu/LoweringCV18xx.h"
#include "llvm/Support/Debug.h"

#define DEBUG_TYPE "lowering-gru"

namespace tpu_mlir {
namespace cv18xx {

void GRULowering::LoweringINT8(PatternRewriter &rewriter, top::GRUOp op,
                               bool asymmetric) const {
  LoweringBF16(rewriter, op);
}

void GRULowering::LoweringBF16(PatternRewriter &rewriter, top::GRUOp op) const {
  std::vector<Value> fc_operands;
  std::vector<Value> gru_operands;
  auto input_shape = Module::getShape(op.input());
  auto filter_shape = Module::getShape(op.filter());
  auto filter_op = dyn_cast<top::WeightOp>(op.filter().getDefiningOp());
  auto filter_data = filter_op.read<float>();
  auto filter_name = Module::getName(op.filter()).str();
  int64_t N = filter_shape[0] * filter_shape[1];
  int64_t K = filter_shape[2];

  int64_t num_dir = op.bidirectional() ? 2 : 1;
  int64_t hidden_size = filter_shape[1] / 3;
  int64_t seq_length = input_shape[0];
  int64_t batch_size = input_shape[1];
  // int64_t input_size = input_shape[2];

  // create fc weight
  std::vector<int64_t> fc_weight_shape = {K, N};
  std::vector<float> fc_filter_data(filter_data->size());
  tensor_hw_transpose(fc_filter_data.data(), filter_data->data(), 1, 1, N, K);

  auto fc_weight_type =
      RankedTensorType::get(fc_weight_shape, rewriter.getF32Type());
  auto fc_weight_operand = top::WeightOp::create(
      op, filter_name + "_FC", fc_filter_data, fc_weight_type);

  // create fc bias
  std::vector<int64_t> bias_shape;
  Module::getShapeVec(op.bias(), bias_shape);
  auto bias_op = dyn_cast<top::WeightOp>(op.bias().getDefiningOp());
  auto bias_data = bias_op.read<float>();
  auto bias_name = Module::getName(op.bias()).str();

  std::vector<std::vector<float>> bias_split_data;
  tensor_split(bias_data->data(), bias_split_data, bias_shape, 2, 1);
  std::vector<int64_t> fc_bias_shape = {N};
  auto fc_bias_type =
      RankedTensorType::get(fc_bias_shape, rewriter.getF32Type());
  auto fc_bias_operand = top::WeightOp::create(
      op, bias_name + "_FC", bias_split_data[0], fc_bias_type);

  // create fc
  std::vector<int64_t> fc_shape = {seq_length, batch_size, N};
  fc_operands.emplace_back(op.input());
  fc_operands.emplace_back(fc_weight_operand);
  fc_operands.emplace_back(fc_bias_operand);
  std::string fc_name = Module::getName(op.input()).str() + "_FC";
  auto loc = NameLoc::get(rewriter.getStringAttr(fc_name));
  auto fc_type = RankedTensorType::get(fc_shape, rewriter.getF32Type());
  auto fc_op = rewriter.create<top::MatMulOp>(loc, fc_type, fc_operands);

  // create gru bias
  std::vector<int64_t> gru_bias_shape = {num_dir, 3 * hidden_size};
  auto gru_bias_type =
      RankedTensorType::get(gru_bias_shape, rewriter.getF32Type());
  auto gru_bias_operand = top::WeightOp::create(
      op, bias_name + "_bias", bias_split_data[1], gru_bias_type);

  // create tpu::gru
  auto none_op = Module::getNoneOp(op);
  auto gru_r_weight_op =
      dyn_cast<top::WeightOp>(op.recurrence().getDefiningOp());
  auto gru_h_weight_op =
      dyn_cast<top::WeightOp>(op.initial_h().getDefiningOp());

  gru_operands.emplace_back(fc_op);
  gru_operands.emplace_back(none_op);
  gru_operands.emplace_back(gru_r_weight_op.clone_bf16(op));
  gru_operands.emplace_back(gru_bias_operand);
  gru_operands.emplace_back(gru_h_weight_op.clone_bf16(op));
  gru_operands.emplace_back(none_op);

  // create lut
  std::string gru_name = Module::getName(op.input()).str() + "_gru";
  mlir::Value s_table, s_mantissa;
  mlir::Value t_table, t_mantissa;
  auto sigmoid_f = [](double x) { return 1.0 / (1 + expf(-x)); };
  auto tanh_f = [](double x) { return tanh(x); };
  createBf16LutOp(op, "sigmoid", TableMode::Slope, 1.0, 0.0, -12, 12, sigmoid_f, s_table, s_mantissa);
  createBf16LutOp(op, "tanh", TableMode::Slope, 1.0, 0.0, -15, 15, tanh_f, t_table, t_mantissa);
  gru_operands.emplace_back(s_table);
  gru_operands.emplace_back(s_mantissa);
  gru_operands.emplace_back(t_table);
  gru_operands.emplace_back(t_mantissa);

  std::vector<NamedAttribute> attrs;
  for (auto &attr : op->getAttrs()) {
    attrs.push_back(attr);
  }
  std::vector<int64_t> gru_shape = {seq_length, num_dir, batch_size,
                                    hidden_size};
  std::vector<Type> gru_types;
  for (auto out : op.getResults()) {
    gru_types.push_back(getQuantBF16Type(out));
  }
  rewriter.replaceOpWithNewOp<tpu::GRUOp>(op.getOperation(), gru_types,
                                          gru_operands, attrs);
  return;
}

} // namespace cv18xx
} // namespace tpu_mlir
