#include <functional>
#include "LoginMqTask.h"

#include "libserver/MqSession.h"
#include "libmessage/Message.h"

using namespace SystemMsg;
using namespace SystemCmd;
using namespace ErrorCode;

LoginMqTask::LoginMqTask(IoLoop& io_loop) : m_io_loop(io_loop)
{
	TRACE_FUNCATION();
}

void LoginMqTask::handle_message(const MqMsgPtr& msg)
{
	m_io_loop.post(std::bind(&LoginMqTask::do_handle_message, this, msg));
}

void LoginMqTask::on_session_close(const MqMsgPtr& msg)
{
	DEBUG_LOG << "session(" << msg->session_ptr().get() << ") close";
}

void LoginMqTask::on_session_open(const MqMsgPtr& msg)
{
	DEBUG_LOG << "session(" << msg->session_ptr().get() << ") open";
}
