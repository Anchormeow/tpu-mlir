#!/bin/bash
set -ex

mkdir -p tmp
pushd tmp

INPUT=../image/dog/download.jpg #1.jpg,2.jpg
model_transform.py \
    --model_type onnx \
    --model_name resnet18 \
    --model_def  ../resnet18.onnx \
    --test_input $INPUT \
    --input_shapes [[1,3,224,224]] \
    --resize_dims '256,256' \
    --keep_aspect_ratio True \
    --mean '103.939,116.778,123.68' \
    --scale '0.0039215,0.0039215,0.0039215' \
    --pixel_format 'bgr_planar' \
    --test_result not_used.npz \
    --mlir resnet18_for_img_cali.mlir

image_list_path=../image/image_list.txt
run_calibration.py resnet18_for_img_cali.mlir \
    --data_list $image_list_path \
    --input_num 2 \
    -o resnet18_cali_table_not_used

INPUT=../resnet18_in_f32.npz
model_transform.py \
    --model_type onnx \
    --model_name resnet18 \
    --input_shapes [[1,3,224,224]] \
    --model_def  ../resnet18.onnx \
    --test_input $INPUT \
    --test_result resnet18_f32_outputs.npz \
    --mlir resnet18.mlir

# do calibration
rm -rf dataset
mkdir -p dataset
cp $INPUT dataset/
run_calibration.py resnet18.mlir \
    --dataset dataset \
    --input_num 1 \
    -o resnet18_cali_table

#########################
# BM1686
#########################

# convert to int8
tpuc-opt resnet18.mlir \
    --import-calibration-table='file=resnet18_cali_table asymmetric=true' \
    --save-weight \
    -o resnet18_cali_1686.mlir

# quantize mlir for 1686 asymmetric
tpuc-opt resnet18_cali_1686.mlir \
    --lowering="mode=INT8 asymmetric=true chip=bm1686" \
    --save-weight \
    -o resnet18_int8_1686_asym.mlir

model_runner.py \
    --model resnet18_int8_1686_asym.mlir \
    --input $INPUT \
    --dump_all_tensors \
    --output resnet18_int8_outputs_1686_asym.npz

npz_tool.py compare \
    resnet18_int8_outputs_1686_asym.npz \
    resnet18_f32_outputs.npz \
    --tolerance 0.90,0.54 -v

# # with layer-group
# tpuc-opt resnet18_int8_1686_asym.mlir \
#     --weight-reorder \
#     --subnet-divide \
#     --layer-group \
#     --address-asign \
#     --save-weight \
#     --codegen="model_file=resnet18_int8_1686_lg.bmodel" \
#     -o resnet18_int8_lg_1686_asym.mlir

# # no layer-group
# tpuc-opt resnet18_int8_1686_asym.mlir \
#     --weight-reorder \
#     --subnet-divide \
#     --address-asign \
#     --save-weight \
#     --codegen="model_file=resnet18_int8_1686.bmodel" \
#     -o resnet18_int8_addr_1686_asym.mlir

tpuc-opt resnet18.mlir \
    --import-calibration-table='file=resnet18_cali_table asymmetric=false' \
    --save-weight \
    -o resnet18_cali_1686_sym.mlir

# quantize mlir for 1686 symmetric
tpuc-opt resnet18_cali_1686_sym.mlir \
    --lowering="mode=INT8 asymmetric=false chip=bm1686" \
    --save-weight \
    -o resnet18_int8_1686_sym.mlir

model_runner.py \
    --model resnet18_int8_1686_sym.mlir \
    --input $INPUT \
    --dump_all_tensors \
    --output resnet18_int8_outputs_1686_sym.npz

npz_tool.py compare \
    resnet18_int8_outputs_1686_sym.npz \
    resnet18_f32_outputs.npz \
    --tolerance 0.95,0.70 -v

# convert f16
tpuc-opt resnet18.mlir \
    '--lowering=mode=F16 chip=bm1686' \
    --save-weight \
    -o resnet18_f16_1686.mlir

model_runner.py \
    --model resnet18_f16_1686.mlir \
    --input $INPUT \
    --dump_all_tensors \
    --output resnet18_f16_outputs_1686.npz

npz_tool.py compare \
    resnet18_f16_outputs_1686.npz \
    resnet18_f32_outputs.npz \
    --tolerance 0.99,0.98 -v

# convert bf16
tpuc-opt resnet18.mlir \
    '--lowering=mode=BF16 chip=bm1686' \
    --save-weight \
    -o resnet18_bf16_1686.mlir

model_runner.py \
    --model resnet18_bf16_1686.mlir \
    --input $INPUT \
    --dump_all_tensors \
    --output resnet18_bf16_outputs_1686.npz

npz_tool.py compare \
    resnet18_bf16_outputs_1686.npz \
    resnet18_f32_outputs.npz \
    --tolerance 0.99,0.96 -v
popd
