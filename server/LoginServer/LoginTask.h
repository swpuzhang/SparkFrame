#ifndef LOGIN_TASK_MANAGER_H
#define LOGIN_TASK_MANAGER_H
#include <vector>
#include <unordered_map>

#include "libmessage/MessageTask.h"
#include "libtools/IoLoop.h"


class LoginModule;

class LoginTask : public TcpTask
{
public:
	using SELF_TYPE = LoginTask;
	LoginTask(IoLoop& io_loop);
	void handle_message(const TcpMsgPtr&) override;

protected:
	void on_session_close(const TcpMsgPtr& msg) override;
	void on_session_open(const TcpMsgPtr& msg) override;
	void on_heart_beat(const TcpMsgPtr& msg) override;
	void on_login(const TcpMsgPtr& msg);
	void on_robot_login(const TcpMsgPtr& msg);
private:
	
	IoLoop& m_io_loop;
};

#endif // !LOGIN_TASK_MANAGER_H