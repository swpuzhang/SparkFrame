// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SvrCmd.proto

#ifndef PROTOBUF_INCLUDED_SvrCmd_2eproto
#define PROTOBUF_INCLUDED_SvrCmd_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_SvrCmd_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_SvrCmd_2eproto {
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
void AddDescriptors_SvrCmd_2eproto();
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
namespace SvrCmd {

enum EnumSvrCmd {
  CMD_BEGIN_FALG = 0,
  CMD_GET_GAMESVR_INSTANCE = 4000,
  CMD_COMMON_QUERY = 4001,
  CMD_SUBMIT_GAME_RESULT = 4002,
  CMD_USERLOG_RECORD = 4003,
  CMD_GAMELOG_RECORD = 4004,
  CMD_APPLOG_RECORD = 4005,
  CMD_ADD_PLAYER_CHIPS = 4006,
  CMD_APPLY_BUYIN = 4007,
  CMD_USER_JOIN_GAME = 4008,
  CMD_USER_LEAVE_GAME = 4009,
  CMD_USER_ENTER_ROOM = 4010,
  CMD_USER_QUIT_ROOM = 4011,
  CMD_GAMESVR_START = 4012,
  CMD_OPEN_GAME_ROOM = 4013,
  CMD_GAME_ROOM_EMPTY = 4014,
  CMD_GAMESVR_ALIVE = 4015,
  CMD_USER_CHIPS_LOG = 4016,
  CMD_HALL_START_UP = 4017,
  CMD_FLUSH_USER_ONLINE = 4018,
  CMD_TELL_USER_OFFLINE = 4019,
  CMD_FLUSH_USER_IN_GAME = 4020,
  CMD_DISPATCH_USER_MSG = 4021,
  CMD_HALL_LOGIN_RECORD = 4022,
  CMD_GAME_LOGIN_RECORD = 4023,
  CMD_CHECK_USER_TOKEN = 4024,
  CMD_KICK_OUT_USER = 4025,
  CMD_GET_INGAME_COUNT = 4026,
  CMD_CHECK_USER_LOGIN = 4027,
  CMD_FORBIDDEN_USER = 4028,
  CMD_FLUSH_USER_GAMESESSION = 4029,
  CMD_TELL_USER_LOGOUT_GAME = 4030,
  CMD_GAME_BUY_CHIPS_IN = 4031,
  CMD_GAME_OVER_ACCOUNT = 4032,
  CMD_GAME_LEAVE_ACCOUNT = 4033,
  CMD_USER_BOX_TIME_RECOVER = 4034,
  CMD_USER_BOX_TIME_PAUSE = 4035,
  CMD_GAME_START_BET = 4036,
  CMD_GAME_ADD_CARRY = 4037,
  CMD_MATCH_OVER_ACCOUNT = 4038,
  CMD_SNGLOG_RECORD = 4039,
  CMD_SNG_GAMELOG_RECORD = 4040,
  CMD_BANKRUPT_LOG = 4041,
  CMD_USER_LOGIN_DCENTER = 4042,
  CMD_USER_LOGIN_GAMESVR = 4043,
  CMD_NOTIFY_OPEN = 4044,
  CMD_QUERY_ROOMMATCHER = 4045,
  CMD_ROOMMATCHER_STATUS = 4046,
  CMD_NOTIFY_TOKEN_LOGIN = 4047,
  EnumSvrCmd_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  EnumSvrCmd_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool EnumSvrCmd_IsValid(int value);
const EnumSvrCmd EnumSvrCmd_MIN = CMD_BEGIN_FALG;
const EnumSvrCmd EnumSvrCmd_MAX = CMD_NOTIFY_TOKEN_LOGIN;
const int EnumSvrCmd_ARRAYSIZE = EnumSvrCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* EnumSvrCmd_descriptor();
inline const ::std::string& EnumSvrCmd_Name(EnumSvrCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    EnumSvrCmd_descriptor(), value);
}
inline bool EnumSvrCmd_Parse(
    const ::std::string& name, EnumSvrCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EnumSvrCmd>(
    EnumSvrCmd_descriptor(), name, value);
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

}  // namespace SvrCmd

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::SvrCmd::EnumSvrCmd> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SvrCmd::EnumSvrCmd>() {
  return ::SvrCmd::EnumSvrCmd_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_SvrCmd_2eproto