// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SystemCmd.proto

#ifndef PROTOBUF_INCLUDED_SystemCmd_2eproto
#define PROTOBUF_INCLUDED_SystemCmd_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3006001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_SystemCmd_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_SystemCmd_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_SystemCmd_2eproto();
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
namespace SystemCmd {

enum EnumSystemCmd {
  CMD_UNKNOWN = 0,
  CMD_HEARTBEAT = 1,
  CMD_SESSION_OPEN = 2,
  CMD_SESSION_CLOSE = 3,
  CMD_CONNECT_FAILED = 4,
  CMD_COMM_RPC = 5,
  CMD_SHUTDOWN_SESSION = 6,
  CMD_SESSION_SILENT = 7,
  CMD_SITE_REGISTER_BUS = 8,
  CMD_SITE_TO_BUS_TRANSMIT = 9,
  CMD_BUS_TO_SITE_TRANSMIT = 10,
  CMD_SESSION_REOPEN = 11,
  CMD_STREAM_OVER_CTRL = 12,
  CMD_MQ_TRANSMIT = 13,
  EnumSystemCmd_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  EnumSystemCmd_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool EnumSystemCmd_IsValid(int value);
const EnumSystemCmd EnumSystemCmd_MIN = CMD_UNKNOWN;
const EnumSystemCmd EnumSystemCmd_MAX = CMD_MQ_TRANSMIT;
const int EnumSystemCmd_ARRAYSIZE = EnumSystemCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* EnumSystemCmd_descriptor();
inline const ::std::string& EnumSystemCmd_Name(EnumSystemCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    EnumSystemCmd_descriptor(), value);
}
inline bool EnumSystemCmd_Parse(
    const ::std::string& name, EnumSystemCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EnumSystemCmd>(
    EnumSystemCmd_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace SystemCmd

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::SystemCmd::EnumSystemCmd> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SystemCmd::EnumSystemCmd>() {
  return ::SystemCmd::EnumSystemCmd_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_SystemCmd_2eproto
