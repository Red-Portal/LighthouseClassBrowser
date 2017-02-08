// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LighthouseCodeElement.proto

#ifndef PROTOBUF_LighthouseCodeElement_2eproto__INCLUDED
#define PROTOBUF_LighthouseCodeElement_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Lighthouse {
namespace CodeElement {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_LighthouseCodeElement_2eproto();
void protobuf_AssignDesc_LighthouseCodeElement_2eproto();
void protobuf_ShutdownFile_LighthouseCodeElement_2eproto();

class CodeElement;

enum CodeElement_ElementType {
  CodeElement_ElementType_TOP = 0,
  CodeElement_ElementType_NAMESPACE = 1,
  CodeElement_ElementType_CLASS = 2,
  CodeElement_ElementType_MEMBER = 3,
  CodeElement_ElementType_METHOD = 4,
  CodeElement_ElementType_COLLECTION = 5,
  CodeElement_ElementType_EXCEPTION = 6,
  CodeElement_ElementType_CodeElement_ElementType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CodeElement_ElementType_CodeElement_ElementType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CodeElement_ElementType_IsValid(int value);
const CodeElement_ElementType CodeElement_ElementType_ElementType_MIN = CodeElement_ElementType_TOP;
const CodeElement_ElementType CodeElement_ElementType_ElementType_MAX = CodeElement_ElementType_EXCEPTION;
const int CodeElement_ElementType_ElementType_ARRAYSIZE = CodeElement_ElementType_ElementType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CodeElement_ElementType_descriptor();
inline const ::std::string& CodeElement_ElementType_Name(CodeElement_ElementType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CodeElement_ElementType_descriptor(), value);
}
inline bool CodeElement_ElementType_Parse(
    const ::std::string& name, CodeElement_ElementType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CodeElement_ElementType>(
    CodeElement_ElementType_descriptor(), name, value);
}
// ===================================================================

class CodeElement : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Lighthouse.CodeElement.CodeElement) */ {
 public:
  CodeElement();
  virtual ~CodeElement();

  CodeElement(const CodeElement& from);

  inline CodeElement& operator=(const CodeElement& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CodeElement& default_instance();

  void Swap(CodeElement* other);

  // implements Message ----------------------------------------------

  inline CodeElement* New() const { return New(NULL); }

  CodeElement* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CodeElement& from);
  void MergeFrom(const CodeElement& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CodeElement* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef CodeElement_ElementType ElementType;
  static const ElementType TOP =
    CodeElement_ElementType_TOP;
  static const ElementType NAMESPACE =
    CodeElement_ElementType_NAMESPACE;
  static const ElementType CLASS =
    CodeElement_ElementType_CLASS;
  static const ElementType MEMBER =
    CodeElement_ElementType_MEMBER;
  static const ElementType METHOD =
    CodeElement_ElementType_METHOD;
  static const ElementType COLLECTION =
    CodeElement_ElementType_COLLECTION;
  static const ElementType EXCEPTION =
    CodeElement_ElementType_EXCEPTION;
  static inline bool ElementType_IsValid(int value) {
    return CodeElement_ElementType_IsValid(value);
  }
  static const ElementType ElementType_MIN =
    CodeElement_ElementType_ElementType_MIN;
  static const ElementType ElementType_MAX =
    CodeElement_ElementType_ElementType_MAX;
  static const int ElementType_ARRAYSIZE =
    CodeElement_ElementType_ElementType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ElementType_descriptor() {
    return CodeElement_ElementType_descriptor();
  }
  static inline const ::std::string& ElementType_Name(ElementType value) {
    return CodeElement_ElementType_Name(value);
  }
  static inline bool ElementType_Parse(const ::std::string& name,
      ElementType* value) {
    return CodeElement_ElementType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string _name = 1;
  void clear__name();
  static const int kNameFieldNumber = 1;
  const ::std::string& _name() const;
  void set__name(const ::std::string& value);
  void set__name(const char* value);
  void set__name(const char* value, size_t size);
  ::std::string* mutable__name();
  ::std::string* release__name();
  void set_allocated__name(::std::string* _name);

  // optional bytes _data1 = 2;
  void clear__data1();
  static const int kData1FieldNumber = 2;
  const ::std::string& _data1() const;
  void set__data1(const ::std::string& value);
  void set__data1(const char* value);
  void set__data1(const void* value, size_t size);
  ::std::string* mutable__data1();
  ::std::string* release__data1();
  void set_allocated__data1(::std::string* _data1);

  // optional bytes _data2 = 3;
  void clear__data2();
  static const int kData2FieldNumber = 3;
  const ::std::string& _data2() const;
  void set__data2(const ::std::string& value);
  void set__data2(const char* value);
  void set__data2(const void* value, size_t size);
  ::std::string* mutable__data2();
  ::std::string* release__data2();
  void set_allocated__data2(::std::string* _data2);

  // optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 4;
  void clear__type();
  static const int kTypeFieldNumber = 4;
  ::Lighthouse::CodeElement::CodeElement_ElementType _type() const;
  void set__type(::Lighthouse::CodeElement::CodeElement_ElementType value);

  // optional bool _isAbstract = 6;
  void clear__isabstract();
  static const int kIsAbstractFieldNumber = 6;
  bool _isabstract() const;
  void set__isabstract(bool value);

  // optional bool _isStatic = 7;
  void clear__isstatic();
  static const int kIsStaticFieldNumber = 7;
  bool _isstatic() const;
  void set__isstatic(bool value);

  // repeated .Lighthouse.CodeElement.CodeElement _child = 8;
  int _child_size() const;
  void clear__child();
  static const int kChildFieldNumber = 8;
  const ::Lighthouse::CodeElement::CodeElement& _child(int index) const;
  ::Lighthouse::CodeElement::CodeElement* mutable__child(int index);
  ::Lighthouse::CodeElement::CodeElement* add__child();
  ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >*
      mutable__child();
  const ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >&
      _child() const;

  // @@protoc_insertion_point(class_scope:Lighthouse.CodeElement.CodeElement)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr _name_;
  ::google::protobuf::internal::ArenaStringPtr _data1_;
  ::google::protobuf::internal::ArenaStringPtr _data2_;
  int _type_;
  bool _isabstract_;
  bool _isstatic_;
  ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement > _child_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_LighthouseCodeElement_2eproto();
  friend void protobuf_AssignDesc_LighthouseCodeElement_2eproto();
  friend void protobuf_ShutdownFile_LighthouseCodeElement_2eproto();

  void InitAsDefaultInstance();
  static CodeElement* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CodeElement

// optional string _name = 1;
inline void CodeElement::clear__name() {
  _name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CodeElement::_name() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._name)
  return _name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set__name(const ::std::string& value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._name)
}
inline void CodeElement::set__name(const char* value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Lighthouse.CodeElement.CodeElement._name)
}
inline void CodeElement::set__name(const char* value, size_t size) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Lighthouse.CodeElement.CodeElement._name)
}
inline ::std::string* CodeElement::mutable__name() {
  
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._name)
  return _name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CodeElement::release__name() {
  // @@protoc_insertion_point(field_release:Lighthouse.CodeElement.CodeElement._name)
  
  return _name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set_allocated__name(::std::string* _name) {
  if (_name != NULL) {
    
  } else {
    
  }
  _name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _name);
  // @@protoc_insertion_point(field_set_allocated:Lighthouse.CodeElement.CodeElement._name)
}

// optional bytes _data1 = 2;
inline void CodeElement::clear__data1() {
  _data1_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CodeElement::_data1() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._data1)
  return _data1_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set__data1(const ::std::string& value) {
  
  _data1_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._data1)
}
inline void CodeElement::set__data1(const char* value) {
  
  _data1_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Lighthouse.CodeElement.CodeElement._data1)
}
inline void CodeElement::set__data1(const void* value, size_t size) {
  
  _data1_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Lighthouse.CodeElement.CodeElement._data1)
}
inline ::std::string* CodeElement::mutable__data1() {
  
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._data1)
  return _data1_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CodeElement::release__data1() {
  // @@protoc_insertion_point(field_release:Lighthouse.CodeElement.CodeElement._data1)
  
  return _data1_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set_allocated__data1(::std::string* _data1) {
  if (_data1 != NULL) {
    
  } else {
    
  }
  _data1_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _data1);
  // @@protoc_insertion_point(field_set_allocated:Lighthouse.CodeElement.CodeElement._data1)
}

// optional bytes _data2 = 3;
inline void CodeElement::clear__data2() {
  _data2_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CodeElement::_data2() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._data2)
  return _data2_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set__data2(const ::std::string& value) {
  
  _data2_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._data2)
}
inline void CodeElement::set__data2(const char* value) {
  
  _data2_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Lighthouse.CodeElement.CodeElement._data2)
}
inline void CodeElement::set__data2(const void* value, size_t size) {
  
  _data2_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Lighthouse.CodeElement.CodeElement._data2)
}
inline ::std::string* CodeElement::mutable__data2() {
  
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._data2)
  return _data2_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CodeElement::release__data2() {
  // @@protoc_insertion_point(field_release:Lighthouse.CodeElement.CodeElement._data2)
  
  return _data2_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CodeElement::set_allocated__data2(::std::string* _data2) {
  if (_data2 != NULL) {
    
  } else {
    
  }
  _data2_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _data2);
  // @@protoc_insertion_point(field_set_allocated:Lighthouse.CodeElement.CodeElement._data2)
}

// optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 4;
inline void CodeElement::clear__type() {
  _type_ = 0;
}
inline ::Lighthouse::CodeElement::CodeElement_ElementType CodeElement::_type() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._Type)
  return static_cast< ::Lighthouse::CodeElement::CodeElement_ElementType >(_type_);
}
inline void CodeElement::set__type(::Lighthouse::CodeElement::CodeElement_ElementType value) {
  
  _type_ = value;
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._Type)
}

// optional bool _isAbstract = 6;
inline void CodeElement::clear__isabstract() {
  _isabstract_ = false;
}
inline bool CodeElement::_isabstract() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._isAbstract)
  return _isabstract_;
}
inline void CodeElement::set__isabstract(bool value) {
  
  _isabstract_ = value;
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._isAbstract)
}

// optional bool _isStatic = 7;
inline void CodeElement::clear__isstatic() {
  _isstatic_ = false;
}
inline bool CodeElement::_isstatic() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._isStatic)
  return _isstatic_;
}
inline void CodeElement::set__isstatic(bool value) {
  
  _isstatic_ = value;
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._isStatic)
}

// repeated .Lighthouse.CodeElement.CodeElement _child = 8;
inline int CodeElement::_child_size() const {
  return _child_.size();
}
inline void CodeElement::clear__child() {
  _child_.Clear();
}
inline const ::Lighthouse::CodeElement::CodeElement& CodeElement::_child(int index) const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Get(index);
}
inline ::Lighthouse::CodeElement::CodeElement* CodeElement::mutable__child(int index) {
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Mutable(index);
}
inline ::Lighthouse::CodeElement::CodeElement* CodeElement::add__child() {
  // @@protoc_insertion_point(field_add:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >*
CodeElement::mutable__child() {
  // @@protoc_insertion_point(field_mutable_list:Lighthouse.CodeElement.CodeElement._child)
  return &_child_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >&
CodeElement::_child() const {
  // @@protoc_insertion_point(field_list:Lighthouse.CodeElement.CodeElement._child)
  return _child_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace CodeElement
}  // namespace Lighthouse

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Lighthouse::CodeElement::CodeElement_ElementType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Lighthouse::CodeElement::CodeElement_ElementType>() {
  return ::Lighthouse::CodeElement::CodeElement_ElementType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_LighthouseCodeElement_2eproto__INCLUDED
