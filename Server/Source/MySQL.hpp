#pragma once

#include <iostream>

#include "../../Extern/MySQL/mysql.h"

extern MYSQL* conn;
extern MYSQL_ROW row;
extern MYSQL_RES* res;
extern std::string conf_ip, conf_login, conf_password, conf_db;
extern unsigned int conf_port;

namespace MySQL
{
	void Connect(std::string ip, std::string login, std::string password, std::string db, unsigned int port);
	void ExecuteQuery(std::string query);
	void SetDatabase(std::string current_db);
}
