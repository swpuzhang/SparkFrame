// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LobbyCmd.proto

#include "LobbyCmd.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace LobbyCmd {
}  // namespace LobbyCmd
void InitDefaults_LobbyCmd_2eproto() {
}

constexpr ::google::protobuf::Metadata* file_level_metadata_LobbyCmd_2eproto = nullptr;
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_LobbyCmd_2eproto[1];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_LobbyCmd_2eproto = nullptr;
const ::google::protobuf::uint32 TableStruct_LobbyCmd_2eproto::offsets[1] = {};
static constexpr ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static constexpr ::google::protobuf::Message* const* file_default_instances = NULL;

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_LobbyCmd_2eproto = {
  {}, AddDescriptors_LobbyCmd_2eproto, "LobbyCmd.proto", schemas,
  file_default_instances, TableStruct_LobbyCmd_2eproto::offsets,
  file_level_metadata_LobbyCmd_2eproto, 0, file_level_enum_descriptors_LobbyCmd_2eproto, file_level_service_descriptors_LobbyCmd_2eproto,
};

::google::protobuf::internal::DescriptorTable descriptor_table_LobbyCmd_2eproto = {
  false, InitDefaults_LobbyCmd_2eproto, 
  "\n\016LobbyCmd.proto\022\010LobbyCmd*\330\003\n\014EnumLobby"
  "Cmd\022\r\n\tCMD_BEGIN\020\000\022\031\n\024CMD_PLAYER_GAME_OV"
  "ER\020\357\017\022\034\n\027CMD_USER_GAME_ROOM_INFO\020\360\017\022\024\n\017C"
  "MD_SEARCH_ROOM\020\361\017\022\033\n\026CMD_GET_MULTIROOM_L"
  "IST\020\362\017\022!\n\034CMD_GET_AUTO_MATCH_MULTIROOM\020\363"
  "\017\022\"\n\035CMD_GET_BLIND_MATCH_MULTIROOM\020\364\017\022#\n"
  "\036CMD_GET_CHANGE_MATCH_MULTIROOM\020\365\017\022\031\n\024CM"
  "D_SEARCH_MULTIROOM\020\366\017\022\034\n\027CMD_PLAYER_CHIP"
  "S_CHANGE\020\331\017\022\034\n\027CMD_PLAYER_COINS_CHANGE\020\332"
  "\017\022\027\n\022CMD_PLAYER_UPGRADE\020\333\017\022\026\n\021CMD_USER_B"
  "ANKRUPT\020\337\017\022\031\n\024CMD_USER_COMM_NOTIFY\020\340\017\022\035\n"
  "\030CMD_PLAYER_CHARM_UPGRADE\020\347\017\022\037\n\032CMD_PLAY"
  "ER_LOGIN_ELSEWHERE\020\351\017"
,
  "LobbyCmd.proto", &assign_descriptors_table_LobbyCmd_2eproto, 501,
};

void AddDescriptors_LobbyCmd_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_LobbyCmd_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_LobbyCmd_2eproto = []() { AddDescriptors_LobbyCmd_2eproto(); return true; }();
namespace LobbyCmd {
const ::google::protobuf::EnumDescriptor* EnumLobbyCmd_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_LobbyCmd_2eproto);
  return file_level_enum_descriptors_LobbyCmd_2eproto[0];
}
bool EnumLobbyCmd_IsValid(int value) {
  switch (value) {
    case 0:
    case 2009:
    case 2010:
    case 2011:
    case 2015:
    case 2016:
    case 2023:
    case 2025:
    case 2031:
    case 2032:
    case 2033:
    case 2034:
    case 2035:
    case 2036:
    case 2037:
    case 2038:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace LobbyCmd
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
