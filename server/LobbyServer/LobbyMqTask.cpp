#include <functional>
#include "LobbyMqTask.h"
#include "libmessage/Message.h"
#include "ErrorCode.pb.h"
#include "LobbyMsg.pb.h"
#include "LobbyCmd.pb.h"
#include "SvrCmd.pb.h"
#include "SvrMsg.pb.h"
#include "SystemCmd.pb.h"
#include "SystemMsg.pb.h"
#include "GameMsg.pb.h"
#include "GameCmd.pb.h"
#include "libserver/MqSession.h"

using namespace SystemMsg;
using namespace SystemCmd;

using namespace SvrMsg;
using namespace SvrCmd;
using namespace LobbyCmd;
using namespace LobbyMsg;
using namespace GameMsg;
using namespace GameCmd;
using namespace ErrorCode;

LobbyMqTask::LobbyMqTask(IoLoop& io_loop) : m_io_loop(io_loop)
{
	TRACE_FUNCATION();
}


void LobbyMqTask::handle_message(const MqMsgPtr& msg)
{
	m_io_loop.post(std::bind(&LobbyMqTask::do_handle_message, this, msg));
}

void LobbyMqTask::on_session_close(const MqMsgPtr& msg)
{
	DEBUG_LOG << "session(" << msg->session_ptr().get() << ") close";
}

void LobbyMqTask::on_session_open(const MqMsgPtr& msg)
{
	DEBUG_LOG << "session(" << msg->session_ptr().get() << ") open";
}
