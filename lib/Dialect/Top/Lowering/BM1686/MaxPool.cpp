//===----------------------------------------------------------------------===//
//
// Copyright (c) 2020-2030 by Sophgo Technologies Inc. All rights reserved.
//
// Licensed under the Apache License v2.0.
// See http://www.apache.org/licenses/LICENSE-2.0 for license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "../Lowering.h"
#include "tpu_mlir/Dialect/Top/IR/TopOps.h"
#include "tpu_mlir/Dialect/Tpu/IR/TpuOps.h"
#include "tpu_mlir/Support/MathUtils.h"
#include "tpu_mlir/Support/Helper/Quant.h"

using namespace mlir;
using namespace tpu_mlir;
using namespace tpu_mlir::helper;

Value top::MaxPoolOp::lowering_int8_bm1686(bool asymetric) {
  return lowering_common_int8<tpu::MaxPoolOp>(getOperation(), asymetric);
}

Value top::MaxPoolOp::lowering_f32_bm1686() {
  return lowering_common<tpu::MaxPoolOp>(getOperation());
}

Value top::MaxPoolOp::lowering_bf16_bm1686() {
  return lowering_common<tpu::MaxPoolOp, BFloat16Type>(getOperation());
}

Value top::MaxPoolOp::lowering_f16_bm1686() {
  return lowering_common<tpu::MaxPoolOp, Float16Type>(getOperation());
}
