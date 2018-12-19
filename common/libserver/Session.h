#ifndef SESSION_H
#define SESSION_H
#define BOOST_THREAD_PROVIDES_FUTURE
#include "libtools/Types.h"
#include "libtools/Types.h"
#include "libmessage/MessageBuffer.h"
#include "libmessage/Message.h"
#include "Synrequest.h"
#include "AsyncRequest.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/thread/future.hpp>
#include <boost/asio.hpp>
#include <memory>
#include <chrono>
#include <atomic>


class MessageQueue;

template <typename MsgTag>
class MessageTask;

class MessageMaker;

class IoLoop;

template <typename MsgTag>
class Session : public std::enable_shared_from_this<Session<MsgTag>>
{
public:
	using QUEUE_PTR = std::shared_ptr<MessageQueue>;
	using SELF_TYPE = Session<MsgTag>;
	

	virtual ~Session();
	//Session(boost::asio::io_context& service);
	Session(IoLoop& io_loop,
		const std::shared_ptr<MessageTask<MsgTag> >& msg_task,
		const std::shared_ptr<MessageMaker>& msg_maker);
	MessagePtr<MsgTag> make_response(const int cmd_type);

	void close();

	void send(const MessagePtr<MsgTag>& msg);

	void send(const MessagePtr<MsgTag>& msg, const ASYNC_FUN<MsgTag>& fun,
		const std::chrono::milliseconds &millisenconds,
		IoLoop* io_loop = nullptr);

	void asyn_response_come(const MessagePtr<MsgTag>& msg);

	bool send_response(const MessagePtr<MsgTag>& msg);

	IoLoop& get_io_loop() { return  m_io_loop; }

	void write_fun(MessagePtr<MsgTag> msg);

	virtual int get_heartbeat_interval() { return 0; }

protected:

	void do_session_open();

	void set_msg_sequenceid(const MessagePtr<MsgTag>& msg);

	bool send_pre_deal(const MessagePtr<MsgTag>& msg);

	void do_send_message(MessagePtr<MsgTag> msg);

	void do_send_asyn_message(MessagePtr<MsgTag> msg, const ASYNC_FUN<MsgTag> fun, 
		const std::chrono::milliseconds millisenconds,
		IoLoop* io_loop);

	virtual void do_write(MessagePtr<MsgTag> msg) = 0;

	void close_fun();

	virtual void do_close() = 0;

	void handle_recv_message(const MessagePtr<MsgTag>& msg);

protected:
	IoLoop& m_io_loop;
	std::shared_ptr<MessageTask<MsgTag>> m_msg_task;
	std::shared_ptr<MessageMaker> m_msg_maker;
	AsyncRequest<MsgTag> m_async_request;
	std::atomic<TY_UINT64> m_sequenceid;
};

#include "Session.inl"
#endif