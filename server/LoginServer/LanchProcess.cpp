#include <cstdio>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <signal.h>
#include <cstdlib>
#include <cstring>

#include "LanchProcess.h"
#include "LoginTask.h"
#include "LoginMqTask.h"
#include "LoginModule.h"
#include "LoginMsgFactor.h"

#include "libserver/Server.h"
#include "libtools/MultiProcess.h"
#include "libtools/IoLoop.h"
#include "libtools/IoLoopPool.h"
#include "libmessage/MessageTask.h"
#include "libmessage/MessageMaker.h"
#include "libtools/Types.h"
#include "libtools/SystemTool.h"
#include "libresource/Mongodb.h"
#include "libresource/Redis.h"

bool LanchProcess::parse_config()
{
	//��ȡ��server������
	std::string process_name = SystemTool::get_process_name();
	Json &jv_server_config = m_config_json[process_name];
	if (!jv_server_config.is_valid())
	{
		return false;
	}
	//�ӽ�������
	int sub_count = atoi(jv_server_config["sub_process"].get<std::string>().c_str());
	//��ʼ�˿�
	int port = atoi(jv_server_config["port"].get<std::string>().c_str());
	assert(sub_count > 0 && sub_count < 100);
	for (int i = 0; i < sub_count; ++i)
	{
		m_ports.push_back(port + i);
	}

	//��ȡhost����
	//��������IP
	m_local_ip = m_config_json["host_config"]["ip"];
	LoginModule::m_local_ip = (boost::asio::ip::address_v4::from_string(m_local_ip).to_uint());

	//��ȡ�����б�
	Json &jv_lobby_list = m_config_json["host_config"]["lobby_list"];
	if (!jv_lobby_list.is_valid() || !jv_lobby_list.is_array())
	{
		return false;
	}
	std::set<std::pair<std::string, TY_UINT16>> hosts;
	for (size_t i = 0; i < jv_lobby_list.size(); ++i)
	{
		std::string str_ip = jv_lobby_list[i]["ip"];
		for (auto &e : jv_lobby_list[i]["ports"])
		{
			hosts.insert({ str_ip,   atoi(e.get<std::string>().c_str()) });
		}
	}
	std::copy(hosts.begin(), hosts.end(), std::back_inserter(LoginModule::m_lobby_list));
	return true;
}

void LanchProcess::run(int argc, char *argv[])
{
	std::srand(std::time(nullptr));
	m_config_file = "./config/config.json";
	std::string  config_str = FileTool::get_file_content(m_config_file);
	//���������ļ�
	m_config_json = Json::parse(config_str);
	parse_config();
	m_argv = std::vector<std::string>(argv, argv + argc);

	//����һ����loop ���߳�
	std::shared_ptr<IoLoopPool> main_pool = std::make_shared<IoLoopPool>(1);
	
	//�����ź�, linux�ϴ����ź�, ���ⴰ�ڹرպ�, �����˳�
#ifndef _WIN32
	std::unique_ptr<boost::asio::signal_set> signals =
		std::make_unique<boost::asio::signal_set>(main_pool->get_next_loop(), SIGPIPE, SIGQUIT, SIGHUP);
	signals->async_wait(std::bind(&LanchProcess::handle_single, this));
#endif // _WIN32

	//����mongo��redis�����ļ�
	MongodbInstance::get_mutable_instance().parse_config(m_config_json["mongo"]);
	RedisInstance::get_mutable_instance().parse_config(m_config_json["redis"]);

	if (argc == 1)
	{
		m_is_master = true;
	}

	if (m_is_master)
	{
		int i = 1;
		for (auto & e : m_ports)
		{
			m_multi_process.creat_process(m_argv[0] + " " + std::to_string(i++) + " " + std::to_string(e), 1);
		}
		
		main_pool->run(false);
	}
	else
	{
		int port =  atoi(m_argv[2].c_str());
		auto task_io_pool = std::make_shared<IoLoopPool>(1);
		auto mq_io_loop = std::make_shared<IoLoopPool>(1);
		//��¼ģ��
		LoginInstance::get_mutable_instance().open(task_io_pool->get_next_loop_ptr());

		//���߼��߳���Ҫ�õ�mongo��redis
		task_io_pool->init_resource();

		//��Ϣ������
		auto msg_maker = std::make_shared<LoginMsgFactor>();
		//mq
		auto mq_task = std::make_shared<LoginMqTask>(task_io_pool->get_next_loop());
		m_mq_client = std::make_unique<MqClient>(main_pool->get_next_loop(),
			config_str, "", mq_task, msg_maker);
		m_mq_client->connect();

		//tcpserver
		auto task_manager = std::make_shared<LoginTask>(task_io_pool->get_next_loop());
		m_tcp_server = std::make_unique<Server>(main_pool->get_next_loop(),
			task_manager, msg_maker);
		m_tcp_server->start(port);

		bool is_detach = false;
		main_pool->run(is_detach);
		task_io_pool->run(is_detach);
	}
	
}