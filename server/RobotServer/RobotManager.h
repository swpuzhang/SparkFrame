#ifndef  BOTMAN_MANAGER_H
#define BOTMAN_MANAGER_H
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>

#include "MongoInfo.h"
#include "UserCommon.h"

class Robot;

enum class RobotStatus;

using RobotPtr = std::shared_ptr<Robot>;



class RobotManager
{
public:
	using SELF_TYPE = RobotManager;
	RobotManager();
	void load_robot();
private:
	bool create_one_robot();
	const static int MAX_WORK_ROBOT = 1000;
	std::vector<std::string> m_device_names;
	std::unordered_map<RobotStatus, std::string> m_robot_status_name;
	std::unordered_map<int, RobotPtr> m_all_robots;
};

#endif
