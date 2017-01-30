// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LighthouseCodeElement.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "LighthouseCodeElement.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Lighthouse {
namespace CodeElement {

namespace {

const ::google::protobuf::Descriptor* CodeElement_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CodeElement_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* CodeElement_ElementType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_LighthouseCodeElement_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_LighthouseCodeElement_2eproto() {
  protobuf_AddDesc_LighthouseCodeElement_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "LighthouseCodeElement.proto");
  GOOGLE_CHECK(file != NULL);
  CodeElement_descriptor_ = file->message_type(0);
  static const int CodeElement_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _bytedata_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _isselected_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _child_),
  };
  CodeElement_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      CodeElement_descriptor_,
      CodeElement::default_instance_,
      CodeElement_offsets_,
      -1,
      -1,
      -1,
      sizeof(CodeElement),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CodeElement, _is_default_instance_));
  CodeElement_ElementType_descriptor_ = CodeElement_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_LighthouseCodeElement_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      CodeElement_descriptor_, &CodeElement::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_LighthouseCodeElement_2eproto() {
  delete CodeElement::default_instance_;
  delete CodeElement_reflection_;
}

void protobuf_AddDesc_LighthouseCodeElement_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_LighthouseCodeElement_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033LighthouseCodeElement.proto\022\026Lighthous"
    "e.CodeElement\"\223\002\n\013CodeElement\022\r\n\005_name\030\001"
    " \001(\t\022\021\n\t_byteData\030\002 \001(\014\022>\n\005_Type\030\003 \001(\0162/"
    ".Lighthouse.CodeElement.CodeElement.Elem"
    "entType\022\023\n\013_isSelected\030\004 \001(\010\0223\n\006_child\030\005"
    " \003(\0132#.Lighthouse.CodeElement.CodeElemen"
    "t\"X\n\013ElementType\022\007\n\003TOP\020\000\022\016\n\nSOURCEFILE\020"
    "\001\022\r\n\tNAMESPACE\020\002\022\t\n\005CLASS\020\003\022\n\n\006MEMBER\020\004\022"
    "\n\n\006METHOD\020\005b\006proto3", 339);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "LighthouseCodeElement.proto", &protobuf_RegisterTypes);
  CodeElement::default_instance_ = new CodeElement();
  CodeElement::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_LighthouseCodeElement_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_LighthouseCodeElement_2eproto {
  StaticDescriptorInitializer_LighthouseCodeElement_2eproto() {
    protobuf_AddDesc_LighthouseCodeElement_2eproto();
  }
} static_descriptor_initializer_LighthouseCodeElement_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* CodeElement_ElementType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CodeElement_ElementType_descriptor_;
}
bool CodeElement_ElementType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const CodeElement_ElementType CodeElement::TOP;
const CodeElement_ElementType CodeElement::SOURCEFILE;
const CodeElement_ElementType CodeElement::NAMESPACE;
const CodeElement_ElementType CodeElement::CLASS;
const CodeElement_ElementType CodeElement::MEMBER;
const CodeElement_ElementType CodeElement::METHOD;
const CodeElement_ElementType CodeElement::ElementType_MIN;
const CodeElement_ElementType CodeElement::ElementType_MAX;
const int CodeElement::ElementType_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CodeElement::kNameFieldNumber;
const int CodeElement::kByteDataFieldNumber;
const int CodeElement::kTypeFieldNumber;
const int CodeElement::kIsSelectedFieldNumber;
const int CodeElement::kChildFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CodeElement::CodeElement()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Lighthouse.CodeElement.CodeElement)
}

void CodeElement::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

CodeElement::CodeElement(const CodeElement& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Lighthouse.CodeElement.CodeElement)
}

void CodeElement::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  _name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _bytedata_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _type_ = 0;
  _isselected_ = false;
}

CodeElement::~CodeElement() {
  // @@protoc_insertion_point(destructor:Lighthouse.CodeElement.CodeElement)
  SharedDtor();
}

void CodeElement::SharedDtor() {
  _name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _bytedata_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void CodeElement::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CodeElement::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CodeElement_descriptor_;
}

const CodeElement& CodeElement::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_LighthouseCodeElement_2eproto();
  return *default_instance_;
}

CodeElement* CodeElement::default_instance_ = NULL;

CodeElement* CodeElement::New(::google::protobuf::Arena* arena) const {
  CodeElement* n = new CodeElement;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CodeElement::Clear() {
// @@protoc_insertion_point(message_clear_start:Lighthouse.CodeElement.CodeElement)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(CodeElement, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<CodeElement*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(_type_, _isselected_);
  _name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _bytedata_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

  _child_.Clear();
}

bool CodeElement::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Lighthouse.CodeElement.CodeElement)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string _name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable__name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->_name().data(), this->_name().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "Lighthouse.CodeElement.CodeElement._name"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse__byteData;
        break;
      }

      // optional bytes _byteData = 2;
      case 2: {
        if (tag == 18) {
         parse__byteData:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable__bytedata()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse__Type;
        break;
      }

      // optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 3;
      case 3: {
        if (tag == 24) {
         parse__Type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set__type(static_cast< ::Lighthouse::CodeElement::CodeElement_ElementType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse__isSelected;
        break;
      }

      // optional bool _isSelected = 4;
      case 4: {
        if (tag == 32) {
         parse__isSelected:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &_isselected_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse__child;
        break;
      }

      // repeated .Lighthouse.CodeElement.CodeElement _child = 5;
      case 5: {
        if (tag == 42) {
         parse__child:
          DO_(input->IncrementRecursionDepth());
         parse_loop__child:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add__child()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_loop__child;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Lighthouse.CodeElement.CodeElement)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Lighthouse.CodeElement.CodeElement)
  return false;
#undef DO_
}

void CodeElement::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Lighthouse.CodeElement.CodeElement)
  // optional string _name = 1;
  if (this->_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->_name().data(), this->_name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Lighthouse.CodeElement.CodeElement._name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->_name(), output);
  }

  // optional bytes _byteData = 2;
  if (this->_bytedata().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->_bytedata(), output);
  }

  // optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 3;
  if (this->_type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->_type(), output);
  }

  // optional bool _isSelected = 4;
  if (this->_isselected() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->_isselected(), output);
  }

  // repeated .Lighthouse.CodeElement.CodeElement _child = 5;
  for (unsigned int i = 0, n = this->_child_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->_child(i), output);
  }

  // @@protoc_insertion_point(serialize_end:Lighthouse.CodeElement.CodeElement)
}

::google::protobuf::uint8* CodeElement::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Lighthouse.CodeElement.CodeElement)
  // optional string _name = 1;
  if (this->_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->_name().data(), this->_name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Lighthouse.CodeElement.CodeElement._name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->_name(), target);
  }

  // optional bytes _byteData = 2;
  if (this->_bytedata().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->_bytedata(), target);
  }

  // optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 3;
  if (this->_type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->_type(), target);
  }

  // optional bool _isSelected = 4;
  if (this->_isselected() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->_isselected(), target);
  }

  // repeated .Lighthouse.CodeElement.CodeElement _child = 5;
  for (unsigned int i = 0, n = this->_child_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        5, this->_child(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Lighthouse.CodeElement.CodeElement)
  return target;
}

int CodeElement::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:Lighthouse.CodeElement.CodeElement)
  int total_size = 0;

  // optional string _name = 1;
  if (this->_name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->_name());
  }

  // optional bytes _byteData = 2;
  if (this->_bytedata().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->_bytedata());
  }

  // optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 3;
  if (this->_type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->_type());
  }

  // optional bool _isSelected = 4;
  if (this->_isselected() != 0) {
    total_size += 1 + 1;
  }

  // repeated .Lighthouse.CodeElement.CodeElement _child = 5;
  total_size += 1 * this->_child_size();
  for (int i = 0; i < this->_child_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->_child(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CodeElement::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Lighthouse.CodeElement.CodeElement)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const CodeElement* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const CodeElement>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Lighthouse.CodeElement.CodeElement)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Lighthouse.CodeElement.CodeElement)
    MergeFrom(*source);
  }
}

void CodeElement::MergeFrom(const CodeElement& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Lighthouse.CodeElement.CodeElement)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  _child_.MergeFrom(from._child_);
  if (from._name().size() > 0) {

    _name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from._name_);
  }
  if (from._bytedata().size() > 0) {

    _bytedata_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from._bytedata_);
  }
  if (from._type() != 0) {
    set__type(from._type());
  }
  if (from._isselected() != 0) {
    set__isselected(from._isselected());
  }
}

void CodeElement::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Lighthouse.CodeElement.CodeElement)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CodeElement::CopyFrom(const CodeElement& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Lighthouse.CodeElement.CodeElement)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CodeElement::IsInitialized() const {

  return true;
}

void CodeElement::Swap(CodeElement* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CodeElement::InternalSwap(CodeElement* other) {
  _name_.Swap(&other->_name_);
  _bytedata_.Swap(&other->_bytedata_);
  std::swap(_type_, other->_type_);
  std::swap(_isselected_, other->_isselected_);
  _child_.UnsafeArenaSwap(&other->_child_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CodeElement::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CodeElement_descriptor_;
  metadata.reflection = CodeElement_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// CodeElement

// optional string _name = 1;
void CodeElement::clear__name() {
  _name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& CodeElement::_name() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._name)
  return _name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void CodeElement::set__name(const ::std::string& value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._name)
}
 void CodeElement::set__name(const char* value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Lighthouse.CodeElement.CodeElement._name)
}
 void CodeElement::set__name(const char* value, size_t size) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Lighthouse.CodeElement.CodeElement._name)
}
 ::std::string* CodeElement::mutable__name() {
  
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._name)
  return _name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* CodeElement::release__name() {
  // @@protoc_insertion_point(field_release:Lighthouse.CodeElement.CodeElement._name)
  
  return _name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void CodeElement::set_allocated__name(::std::string* _name) {
  if (_name != NULL) {
    
  } else {
    
  }
  _name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _name);
  // @@protoc_insertion_point(field_set_allocated:Lighthouse.CodeElement.CodeElement._name)
}

// optional bytes _byteData = 2;
void CodeElement::clear__bytedata() {
  _bytedata_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& CodeElement::_bytedata() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._byteData)
  return _bytedata_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void CodeElement::set__bytedata(const ::std::string& value) {
  
  _bytedata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._byteData)
}
 void CodeElement::set__bytedata(const char* value) {
  
  _bytedata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Lighthouse.CodeElement.CodeElement._byteData)
}
 void CodeElement::set__bytedata(const void* value, size_t size) {
  
  _bytedata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Lighthouse.CodeElement.CodeElement._byteData)
}
 ::std::string* CodeElement::mutable__bytedata() {
  
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._byteData)
  return _bytedata_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* CodeElement::release__bytedata() {
  // @@protoc_insertion_point(field_release:Lighthouse.CodeElement.CodeElement._byteData)
  
  return _bytedata_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void CodeElement::set_allocated__bytedata(::std::string* _bytedata) {
  if (_bytedata != NULL) {
    
  } else {
    
  }
  _bytedata_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _bytedata);
  // @@protoc_insertion_point(field_set_allocated:Lighthouse.CodeElement.CodeElement._byteData)
}

// optional .Lighthouse.CodeElement.CodeElement.ElementType _Type = 3;
void CodeElement::clear__type() {
  _type_ = 0;
}
 ::Lighthouse::CodeElement::CodeElement_ElementType CodeElement::_type() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._Type)
  return static_cast< ::Lighthouse::CodeElement::CodeElement_ElementType >(_type_);
}
 void CodeElement::set__type(::Lighthouse::CodeElement::CodeElement_ElementType value) {
  
  _type_ = value;
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._Type)
}

// optional bool _isSelected = 4;
void CodeElement::clear__isselected() {
  _isselected_ = false;
}
 bool CodeElement::_isselected() const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._isSelected)
  return _isselected_;
}
 void CodeElement::set__isselected(bool value) {
  
  _isselected_ = value;
  // @@protoc_insertion_point(field_set:Lighthouse.CodeElement.CodeElement._isSelected)
}

// repeated .Lighthouse.CodeElement.CodeElement _child = 5;
int CodeElement::_child_size() const {
  return _child_.size();
}
void CodeElement::clear__child() {
  _child_.Clear();
}
const ::Lighthouse::CodeElement::CodeElement& CodeElement::_child(int index) const {
  // @@protoc_insertion_point(field_get:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Get(index);
}
::Lighthouse::CodeElement::CodeElement* CodeElement::mutable__child(int index) {
  // @@protoc_insertion_point(field_mutable:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Mutable(index);
}
::Lighthouse::CodeElement::CodeElement* CodeElement::add__child() {
  // @@protoc_insertion_point(field_add:Lighthouse.CodeElement.CodeElement._child)
  return _child_.Add();
}
::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >*
CodeElement::mutable__child() {
  // @@protoc_insertion_point(field_mutable_list:Lighthouse.CodeElement.CodeElement._child)
  return &_child_;
}
const ::google::protobuf::RepeatedPtrField< ::Lighthouse::CodeElement::CodeElement >&
CodeElement::_child() const {
  // @@protoc_insertion_point(field_list:Lighthouse.CodeElement.CodeElement._child)
  return _child_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace CodeElement
}  // namespace Lighthouse

// @@protoc_insertion_point(global_scope)