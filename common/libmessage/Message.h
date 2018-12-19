#ifndef MESSAGE_H
#define  MESSAGE_H
#include <memory>
#include <string>

#include "MsgHeader.pb.h"
#include "MessageType.h"

#include "MessageType.h"

#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"
#include "libtools/Types.h"
template <class MsgTag>
class Message;

#define  HEADER(HeaderType, name)\
  auto name = std::make_shared<HeaderType>()
#define  PB_MSG(pb_type,name) \
  auto name = std::make_shared<pb_type>()
#define  EMPTY_MSG(MsgTag, name)\
  std::shared_ptr<Message<MsgTag>> name = std::make_shared<Message<MsgTag>>()

#define  FULL_MSG(HeaderType, headname, PbType, pbname, MsgTag, msgname)\
  auto headname = std::make_shared<HeaderType>();\
  auto pbname = std::make_shared<PbType>();\
  auto msgname = std::make_shared<Message<MsgTag>>();\
  msgname->set_pbmessage(pbname);\
  msgname->set_header(headname)
 
using TcpMsg = Message<TcpTag>;

using MqMsg = Message<MqTag>;

using TcpMsgPtr = std::shared_ptr<TcpMsg>;

using MqMsgPtr = std::shared_ptr<MqMsg>;

class MqSession;

class TcpSession;

using TcpSessionPtr = std::shared_ptr<TcpSession>;

using MqSessionPtr = std::shared_ptr<MqSession>;

enum class MessageType
{
	REQUEST_TYPE = 1,
	RESPONSE_TYPE = 2,
};

template <class MsgTag>
class Message
{
public:
	using HeaderType = typename MsgTag::HeaderType;

	using HeaderPtr = typename MsgTag::HeaderPtr;

	Message();

	bool send_response(const MessagePtr<MsgTag>& response) const;

	bool send_response(int fail_reson, const PbMessagePtr& response) const;

	bool send_failed_reason(const int fail_reson) const;

	void set_session(const SessionPtr<MsgTag>& session) { m_session = session; }

	SessionPtr<MsgTag>& session_ptr()  { return m_session; }

	const SessionPtr<MsgTag>& session_ptr() const { return m_session; }

	template<typename T>
	const std::shared_ptr<T>  session_ptr() const { return std::dynamic_pointer_cast<T>(m_session); }

	template<typename T>
	std::shared_ptr<T>  session_ptr()  { return std::dynamic_pointer_cast<T>(m_session); }

	const PbMessage& pbmessage() const { return *m_message; }

	PbMessage& pbmessage() { return *m_message; }

	template<typename T>
	T& pbmessage() const { return dynamic_cast<T&>(*m_message); }

	void set_pbmessage(const PbMessagePtr& msg) { m_message = msg; }

	PbMessagePtr& pbmessage_ptr() { return m_message; }

	const PbMessagePtr& pbmessage_ptr() const { return m_message; }

	void set_header(const HeaderPtr& header) { m_header = header; }

	HeaderType& header() { return *m_header; }

	const HeaderType& header() const { return *m_header; }
	
	HeaderPtr& header_ptr() { return m_header; }

	const HeaderPtr& header_ptr() const { return m_header; }

private:

	HeaderPtr m_header;
	PbMessagePtr m_message;
	SessionPtr<MsgTag> m_session;
};

#include "Message.inl"

#endif