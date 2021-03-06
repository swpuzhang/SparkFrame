// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LobbyCmd.proto

#ifndef PROTOBUF_INCLUDED_LobbyCmd_2eproto
#define PROTOBUF_INCLUDED_LobbyCmd_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_LobbyCmd_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_LobbyCmd_2eproto {
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
void AddDescriptors_LobbyCmd_2eproto();
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
namespace LobbyCmd {

enum EnumLobbyCmd {
  CMD_BEGIN = 0,
  CMD_PLAYER_GAME_OVER = 2031,
  CMD_USER_GAME_ROOM_INFO = 2032,
  CMD_SEARCH_ROOM = 2033,
  CMD_GET_MULTIROOM_LIST = 2034,
  CMD_GET_AUTO_MATCH_MULTIROOM = 2035,
  CMD_GET_BLIND_MATCH_MULTIROOM = 2036,
  CMD_GET_CHANGE_MATCH_MULTIROOM = 2037,
  CMD_SEARCH_MULTIROOM = 2038,
  CMD_PLAYER_CHIPS_CHANGE = 2009,
  CMD_PLAYER_COINS_CHANGE = 2010,
  CMD_PLAYER_UPGRADE = 2011,
  CMD_USER_BANKRUPT = 2015,
  CMD_USER_COMM_NOTIFY = 2016,
  CMD_PLAYER_CHARM_UPGRADE = 2023,
  CMD_PLAYER_LOGIN_ELSEWHERE = 2025
};
bool EnumLobbyCmd_IsValid(int value);
const EnumLobbyCmd EnumLobbyCmd_MIN = CMD_BEGIN;
const EnumLobbyCmd EnumLobbyCmd_MAX = CMD_SEARCH_MULTIROOM;
const int EnumLobbyCmd_ARRAYSIZE = EnumLobbyCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* EnumLobbyCmd_descriptor();
inline const ::std::string& EnumLobbyCmd_Name(EnumLobbyCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    EnumLobbyCmd_descriptor(), value);
}
inline bool EnumLobbyCmd_Parse(
    const ::std::string& name, EnumLobbyCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EnumLobbyCmd>(
    EnumLobbyCmd_descriptor(), name, value);
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

}  // namespace LobbyCmd

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::LobbyCmd::EnumLobbyCmd> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::LobbyCmd::EnumLobbyCmd>() {
  return ::LobbyCmd::EnumLobbyCmd_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_LobbyCmd_2eproto
