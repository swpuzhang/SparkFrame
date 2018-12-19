#include "MessageQueue.h"
#include "Message.h"
#include <algorithm>

MessageQueue::MessageQueue() : m_message_queue(INIT_SIZE) {}

TcpMsgPtr MessageQueue::pop()
{
	if (m_message_queue.empty())
	{
		return TcpMsgPtr();
	}
	TcpMsgPtr msg = m_message_queue.front();
	m_message_queue.pop_front();
	return msg;
}

bool MessageQueue::push(TcpMsgPtr msg)
{
	SIZE_TYPE all_size = m_message_queue.size();
	if (m_message_queue.full())
	{
		if (MAX_SIZE < all_size)
		{
			return false;
		}
		m_message_queue.set_capacity(all_size + all_size);
	}
	m_message_queue.push_back(msg);
	return true;
}

TcpMsgPtr MessageQueue::front()
{
	if (m_message_queue.empty())
	{
		return TcpMsgPtr();
	}
	return m_message_queue.front();
}