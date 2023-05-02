/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
namespace mlir {
namespace bufferization {
class AllocTensorOp;
} // namespace bufferization
} // namespace mlir
namespace mlir {
namespace bufferization {
class CloneOp;
} // namespace bufferization
} // namespace mlir
namespace mlir {
namespace bufferization {
class DeallocTensorOp;
} // namespace bufferization
} // namespace mlir
namespace mlir {
namespace bufferization {
class ToMemrefOp;
} // namespace bufferization
} // namespace mlir
namespace mlir {
namespace bufferization {
class ToTensorOp;
} // namespace bufferization
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::AllocTensorOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllocTensorOpGenericAdaptorBase {
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::std::optional<::mlir::OperationName> odsOpName;
public:
  AllocTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::Attribute getMemorySpaceAttr();
  ::std::optional<::mlir::Attribute> getMemorySpace();
};
} // namespace detail
template <typename RangeT>
class AllocTensorOpGenericAdaptor : public detail::AllocTensorOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllocTensorOpGenericAdaptorBase;
public:
  AllocTensorOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions = {}) : Base(attrs, regions), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getDynamicSizes() {
    return getODSOperands(0);
  }

  ValueT getCopy() {
    auto operands = getODSOperands(1);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  ValueT getSizeHint() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AllocTensorOpAdaptor : public AllocTensorOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllocTensorOpGenericAdaptor::AllocTensorOpGenericAdaptor;
  AllocTensorOpAdaptor(AllocTensorOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class AllocTensorOp : public ::mlir::Op<AllocTensorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::bufferization::BufferizableOpInterface::Trait, ::mlir::ReifyRankedShapedTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllocTensorOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllocTensorOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("memory_space"), ::llvm::StringRef("operand_segment_sizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getMemorySpaceAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getMemorySpaceAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("bufferization.alloc_tensor");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getDynamicSizes();
  ::mlir::TypedValue<::mlir::TensorType> getCopy();
  ::mlir::TypedValue<::mlir::IndexType> getSizeHint();
  ::mlir::MutableOperandRange getDynamicSizesMutable();
  ::mlir::MutableOperandRange getCopyMutable();
  ::mlir::MutableOperandRange getSizeHintMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::TensorType> getResult();
  ::mlir::Attribute getMemorySpaceAttr();
  ::std::optional<::mlir::Attribute> getMemorySpace();
  void setMemorySpaceAttr(::mlir::Attribute attr);
  ::mlir::Attribute removeMemorySpaceAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, RankedTensorType type, ValueRange dynamicSizes);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, RankedTensorType type, ValueRange dynamicSizes, Value copy);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, TensorType type, ValueRange dynamicSizes, Value copy, IntegerAttr memory_space);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::ValueRange dynamic_sizes, /*optional*/::mlir::Value copy, /*optional*/::mlir::Value size_hint, /*optional*/::mlir::Attribute memory_space);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange dynamic_sizes, /*optional*/::mlir::Value copy, /*optional*/::mlir::Value size_hint, /*optional*/::mlir::Attribute memory_space);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::LogicalResult reifyResultShapes(::mlir::OpBuilder &builder, ::mlir::ReifiedRankedShapedTypeDims &reifiedReturnShapes);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
  LogicalResult bufferize(RewriterBase &rewriter,
                          const BufferizationOptions &options);

  bool resultBufferizesToMemoryWrite(OpResult opResult,
                                     const AnalysisState &state);

  bool bufferizesToAllocation(OpResult opResult) { return true; }

  bool bufferizesToMemoryRead(OpOperand &opOperand,
                              const AnalysisState &state);

  bool bufferizesToMemoryWrite(OpOperand &opOperand,
                               const AnalysisState &state);

  AliasingOpResultList getAliasingOpResults(
      OpOperand &opOperand, const AnalysisState &state);

  FailureOr<BaseMemRefType> getBufferType(
      Value value, const BufferizationOptions &options,
      const DenseMap<Value, BaseMemRefType> &fixedTypes);

  RankedTensorType getType() {
    return getResult().getType().cast<RankedTensorType>();
  }

  // Return true if the size of the tensor is dynamic at `idx`
  bool isDynamicDim(unsigned idx) {
    return getType().isDynamicDim(idx);
  }

  // Return the argument position that contains the dynamic size of
  // the tensor at dimension `idx`. Asserts that the shape is
  // dynamic at that `idx`.
  unsigned getIndexOfDynamicSize(unsigned idx) {
    assert(!getCopy() && "no dim sizes specified when copying a tensor");
    assert(isDynamicDim(idx) && "expected dynamic size");
    ArrayRef<int64_t> shape = getType().getShape();
    return std::count_if(
        shape.begin(), shape.begin() + idx,
        [&](int64_t size) { return ShapedType::isDynamic(size); });
  }

  // Return the Value of the dynamic size of the tensor at dimension
  // `idx`. Asserts that the shape is dynamic at that `idx.
  Value getDynamicSize(OpBuilder &b, unsigned idx);

  // Assert that the size of the result tensor is static at `idx`
  // and return the shape.
  int64_t getStaticSize(unsigned idx) {
    assert(!isDynamicDim(idx) && "expected static size");
    return getType().getShape()[idx];
  }
};
} // namespace bufferization
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::bufferization::AllocTensorOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::CloneOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class CloneOpGenericAdaptorBase {
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::std::optional<::mlir::OperationName> odsOpName;
public:
  CloneOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class CloneOpGenericAdaptor : public detail::CloneOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::CloneOpGenericAdaptorBase;
public:
  CloneOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {}) : Base(attrs, regions), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class CloneOpAdaptor : public CloneOpGenericAdaptor<::mlir::ValueRange> {
public:
  using CloneOpGenericAdaptor::CloneOpGenericAdaptor;
  CloneOpAdaptor(CloneOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class CloneOp : public ::mlir::Op<CloneOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::BaseMemRefType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::CopyOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::bufferization::AllocationOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CloneOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = CloneOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("bufferization.clone");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::BaseMemRefType> getInput();
  ::mlir::MutableOperandRange getInputMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::BaseMemRefType> getOutput();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type output, ::mlir::Value input);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(FoldAdaptor adaptor);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
  static ::std::optional<::mlir::Operation*> buildDealloc(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::std::optional<::mlir::Value> buildClone(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
  Value getSource() { return getInput(); }
  Value getTarget() { return getOutput(); }
};
} // namespace bufferization
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::bufferization::CloneOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::DeallocTensorOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DeallocTensorOpGenericAdaptorBase {
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::std::optional<::mlir::OperationName> odsOpName;
public:
  DeallocTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class DeallocTensorOpGenericAdaptor : public detail::DeallocTensorOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DeallocTensorOpGenericAdaptorBase;
public:
  DeallocTensorOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {}) : Base(attrs, regions), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DeallocTensorOpAdaptor : public DeallocTensorOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DeallocTensorOpGenericAdaptor::DeallocTensorOpGenericAdaptor;
  DeallocTensorOpAdaptor(DeallocTensorOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class DeallocTensorOp : public ::mlir::Op<DeallocTensorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::bufferization::BufferizableOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DeallocTensorOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DeallocTensorOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("bufferization.dealloc_tensor");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::TensorType> getTensor();
  ::mlir::MutableOperandRange getTensorMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
  bool bufferizesToMemoryRead(OpOperand &opOperand,
                              const AnalysisState &state) const {
    return false;
  }

  bool bufferizesToMemoryWrite(OpOperand &opOperand,
                               const AnalysisState &state) const {
    return false;
  }

  AliasingOpResultList getAliasingOpResults(
      OpOperand &opOperand, const AnalysisState &state) const {
    return {};
  }

  LogicalResult bufferize(RewriterBase &rewriter,
                          const BufferizationOptions &options);
};
} // namespace bufferization
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::bufferization::DeallocTensorOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::ToMemrefOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ToMemrefOpGenericAdaptorBase {
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::std::optional<::mlir::OperationName> odsOpName;
public:
  ToMemrefOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class ToMemrefOpGenericAdaptor : public detail::ToMemrefOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ToMemrefOpGenericAdaptorBase;
public:
  ToMemrefOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {}) : Base(attrs, regions), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ToMemrefOpAdaptor : public ToMemrefOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ToMemrefOpGenericAdaptor::ToMemrefOpGenericAdaptor;
  ToMemrefOpAdaptor(ToMemrefOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class ToMemrefOp : public ::mlir::Op<ToMemrefOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::BaseMemRefType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::bufferization::BufferizableOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultShape, ::mlir::OpTrait::SameOperandsAndResultElementType, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ToMemrefOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ToMemrefOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("bufferization.to_memref");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::TensorType> getTensor();
  ::mlir::MutableOperandRange getTensorMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::BaseMemRefType> getMemref();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type memref, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(FoldAdaptor adaptor);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  //===------------------------------------------------------------------===//
  // BufferizableOpInterface implementation
  //===------------------------------------------------------------------===//

  // Note: ToMemrefOp / ToTensorOp are temporary ops that are inserted at the
  // bufferization boundary. When One-Shot bufferization is complete, there
  // should be no such ops left over. If `allowUnknownOps` (or after running a
  // partial bufferization pass), such ops may be part of the resulting IR,
  // but such IR may no longer be analyzable by One-Shot analysis.

  bool bufferizesToMemoryRead(OpOperand &opOperand,
                              const AnalysisState &state) const {
    // It is unknown whether the resulting memref will be read or not.
    return true;
  }

  bool bufferizesToMemoryWrite(OpOperand &opOperand,
                               const AnalysisState &state) const {
    // It is unknown whether the resulting MemRef will be written or not.
    return true;
  }

  bool mustBufferizeInPlace(OpOperand &opOperand,
                            const AnalysisState &state) const {
    // ToMemrefOps always bufferize inplace.
    return true;
  }

  AliasingOpResultList getAliasingOpResults(
      OpOperand &opOperand, const AnalysisState &state) const {
    return {};
  }

  LogicalResult bufferize(RewriterBase &rewriter,
                          const BufferizationOptions &options);
};
} // namespace bufferization
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::bufferization::ToMemrefOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::ToTensorOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ToTensorOpGenericAdaptorBase {
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::std::optional<::mlir::OperationName> odsOpName;
public:
  ToTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::UnitAttr getRestrictAttr();
  bool getRestrict();
  ::mlir::UnitAttr getWritableAttr();
  bool getWritable();
};
} // namespace detail
template <typename RangeT>
class ToTensorOpGenericAdaptor : public detail::ToTensorOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ToTensorOpGenericAdaptorBase;
public:
  ToTensorOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {}) : Base(attrs, regions), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getMemref() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ToTensorOpAdaptor : public ToTensorOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ToTensorOpGenericAdaptor::ToTensorOpGenericAdaptor;
  ToTensorOpAdaptor(ToTensorOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class ToTensorOp : public ::mlir::Op<ToTensorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::bufferization::BufferizableOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultShape, ::mlir::OpTrait::SameOperandsAndResultElementType, ::mlir::InferTypeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ToTensorOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ToTensorOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("restrict"), ::llvm::StringRef("writable")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getRestrictAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getRestrictAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getWritableAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getWritableAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("bufferization.to_tensor");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::BaseMemRefType> getMemref();
  ::mlir::MutableOperandRange getMemrefMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::TensorType> getResult();
  ::mlir::UnitAttr getRestrictAttr();
  bool getRestrict();
  ::mlir::UnitAttr getWritableAttr();
  bool getWritable();
  void setRestrictAttr(::mlir::UnitAttr attr);
  void setRestrict(bool attrValue);
  void setWritableAttr(::mlir::UnitAttr attr);
  void setWritable(bool attrValue);
  ::mlir::Attribute removeRestrictAttr();
  ::mlir::Attribute removeWritableAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, /*optional*/bool restrict = false, /*optional*/bool writable = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, /*optional*/bool restrict = false, /*optional*/bool writable = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, /*optional*/bool restrict = false, /*optional*/bool writable = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(FoldAdaptor adaptor);
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
  /// The result of a to_tensor is always a tensor.
  TensorType getType() {
    Type resultType = getResult().getType();
    if (resultType.isa<TensorType>())
      return resultType.cast<TensorType>();
    return {};
  }

  //===------------------------------------------------------------------===//
  // BufferizableOpInterface implementation
  //===------------------------------------------------------------------===//

  LogicalResult bufferize(RewriterBase &rewriter,
                          const BufferizationOptions &options) const {
    // to_tensor/to_memref pairs fold away after bufferization.
    return success();
  }

  bool isWritable(Value value, const AnalysisState &state);

  FailureOr<BaseMemRefType> getBufferType(
      Value value, const BufferizationOptions &options,
      const DenseMap<Value, BaseMemRefType> &fixedTypes) {
    return getMemref().getType().cast<BaseMemRefType>();
  }
};
} // namespace bufferization
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::bufferization::ToTensorOp)


#endif  // GET_OP_CLASSES
