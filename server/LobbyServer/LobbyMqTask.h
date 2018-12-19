#ifndef MQ_TASK_MANAGER_H
#define MQ_TASK_MANAGER_H

#include "libmessage/MessageTask.h"
#include "libtools/IoLoop.h"
#include <vector>
#include <unordered_map>

class LobbyMqTask : public MqTask
{
public:
	using SELF_TYPE = LobbyMqTask;
	LobbyMqTask(IoLoop& io_loop);
	void handle_message(const MqMsgPtr&) override;

protected:
	void on_session_close(const MqMsgPtr& msg) override;
	void on_session_open(const MqMsgPtr& msg) override;
private:
	
	IoLoop& m_io_loop;
};

#endif // !LOGIN_TASK_MANAGER_H