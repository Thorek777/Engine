#pragma once

#ifdef _WIN32
#include "../../Extern/MySQL/mysql.h"
#else
	#include <mysql/mysql.h>
#endif

#include <string>

extern MYSQL* conn;
extern MYSQL_ROW row;
extern MYSQL_RES* res;
extern std::string config[4];
extern unsigned int config_port;

namespace MySQL
{
	int Connect(const std::string& ip, const std::string& login, const std::string& password, const std::string& db,
	            unsigned int port);
	int ExecuteQuery(const std::string& query);
	void SetDatabase(const std::string& current_db);
}
