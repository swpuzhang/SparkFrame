#ifndef TASK_MANAGER_INL
#define TASK_MANAGER_INL
#include "MessageTask.h"
#include "libtools/FunctionBindMacro.h"
#include "liblog/Log.h"
#include "libmessage/Message.h"

#include "SystemCmd.pb.h"
#include "SystemMsg.pb.h"
using namespace SystemCmd;
using namespace SystemMsg;
#include <boost/make_shared.hpp>

template<typename MsgTag>
MessageTask<MsgTag>::MessageTask()
{
}

template<typename MsgTag>
void MessageTask<MsgTag>::register_msg_handler(const CMD_TYPE& cmd, MSG_HANDLER_FUNC<MsgTag> hander)
{
	m_cmd_handler[cmd] = hander;
	DEBUG_LOG << "register_cmd_handler cmdtype:" << cmd;
}

template<typename MsgTag>
void MessageTask<MsgTag>::on_unknown_msg(const MessagePtr<MsgTag>& msg)
{
	DEBUG_LOG << "cmdtype(" << msg->header().cmdtype() << ") have no handler";
}

template<typename MsgTag>
void MessageTask<MsgTag>::on_session_close(const MessagePtr<MsgTag>& msg)
{
	DEBUG_LOG << "cmdtype(" << msg->header().cmdtype() << ") default session_close";
}

template<typename MsgTag>
void MessageTask<MsgTag>::on_session_open(const MessagePtr<MsgTag>& msg)
{
	DEBUG_LOG << "cmdtype(" << msg->header().cmdtype() << ") default session_open";
}

template<typename MsgTag>
void  MessageTask<MsgTag>::do_heart_beat(const MessagePtr<MsgTag>& msg)
{
	TRACE_FUNCATION();
	FULL_MSG(typename MsgTag::HeaderType, head, SystemMsg::HeartbeatResponse, heart_res, MsgTag, res);
	heart_res->set_interval(msg->session_ptr()->get_heartbeat_interval());
	res->set_pbmessage(heart_res);
	res->header().set_cmdtype(SystemCmd::CMD_HEARTBEAT);
	msg->send_response(res);
	this->on_heart_beat(msg);
}

template<typename MsgTag>
void MessageTask<MsgTag>::on_heart_beat(const MessagePtr<MsgTag>& msg)
{
	TRACE_FUNCATION();
	DEBUG_LOG << "cmdtype(" << msg->header().cmdtype() << ") default heart_beat";
}

template<typename MsgTag>
void MessageTask<MsgTag>::do_handle_message(MessagePtr<MsgTag> msg)
{
	DEBUG_LOG << "do_handle_message cmdtype:" << msg->header().cmdtype() << " handler size:" << m_cmd_handler.size();
	if (msg->header().cmdtype() == SystemCmd::CMD_SESSION_OPEN)
	{
		this->on_session_open(msg);
	}
	else if (msg->header().cmdtype() == SystemCmd::CMD_SESSION_CLOSE)
	{
		this->on_session_close(msg);
	}
	else if (msg->header().cmdtype() == SystemCmd::CMD_HEARTBEAT)
	{
		this->do_heart_beat(msg);
	}
	else
	{
		auto it = m_cmd_handler.find(msg->header().cmdtype());
		if (it != m_cmd_handler.end())
		{
			MSG_HANDLER_FUNC<MsgTag> &func = it->second;
			func(msg);
		}
		else
		{
			this->on_unknown_msg(msg);
		}
	}
	
}

template<typename MsgTag>
void MessageTask<MsgTag>::handle_message( const MessagePtr<MsgTag>& msg)
{
	do_handle_message(msg);
}
#endif