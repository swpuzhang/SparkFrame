#ifndef PlayerManager_H__
#define PlayerManager_H__
#include <unordered_map>
#include <boost/serialization/singleton.hpp>
#include <boost/optional.hpp>
#include <boost/bimap.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>

#include "libtools/Types.h"
#include "libtools/JsonParser.h"
#include "libtools/BaseTool.h"
#include "libmessage/Message.h"


class Player;
using PLAYER_PTR = std::shared_ptr<Player>;
constexpr TY_INT64 MAX_LOGIN_SEC = 5;

class PlayerManager
{
public:
	using SELF_TYPE = PlayerManager;
	PlayerManager(void);
	virtual ~PlayerManager(void);

	void on_session_close(const TcpMsgPtr &msg);
	void on_session_open(const TcpMsgPtr &msg);
	bool player_token_login(const TcpMsgPtr &msg);
	bool is_player_online(int user_id);

	PLAYER_PTR make_player(int player_id, const TcpSessionPtr& session);

	void destory_player(const PLAYER_PTR &player);

	void get_all_user(google::protobuf::RepeatedField<google::protobuf::int32 >* pUsers);

	bool check_player_session(int user_id, const TcpSessionPtr& session);

	void on_kick_out_user(const TcpMsgPtr &msg);

    void flush_user_online(const TcpSessionPtr& session);

   // void on_user_response(int user_id, const TcpMsgPtr &request, const TcpMsgPtr &response);

    void output_manager_info(void);

	boost::optional<int> check_user_msg(const TcpMsgPtr &msg);

private:
	void add_user_session(int user_id, const TcpSessionPtr& session);

	TcpSessionPtr recv_session(int user_id);

	void send_login_record(int user_id, TY_UINT8 user_action, const std::string& remote_addr);

	bool check_user_token(const std::string& token, const Json& user_token);
	
	void send_player_login_elsewhere(int user_id, const TcpSessionPtr& session, char reason,std::string description="");

	void shutdown_user_session(const TcpSessionPtr& session);

	void tell_user_logout_game(int user_id);

	void tell_user_login_lobby(int user_id);

	void on_timeout(const SYSTEM_CODE& err_code);
private:
    std::unordered_map<int, PLAYER_PTR> m_login_user;     //key: user_id ,���Ե�½�˵���ң�������ǰ�������ߵ���ң� �������5���Ӻ�ɾ����¼
    std::unordered_map<TcpSessionPtr, PLAYER_PTR> m_online_user;   // key: session_id�� ��ǰ���е�½��ң���ǰ���ߵ����
	std::map<TcpSessionPtr, std::chrono::steady_clock::time_point> m_session_time;  //�������ӵ���Ϣ
	std::unique_ptr<boost::asio::steady_timer > m_timer;
};

using PlayerManagerInstance = boost::serialization::singleton<PlayerManager>;

#endif //PlayerManager_H__


