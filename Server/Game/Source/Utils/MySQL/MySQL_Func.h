#pragma once

#include <iostream>
#include <mysql.h>
#include <string>

extern MYSQL* conn;
extern MYSQL_ROW row;
extern MYSQL_RES* res;
extern std::string conf_ip;
extern unsigned int conf_port;
extern std::string conf_db;
extern std::string conf_login;
extern std::string conf_password;

namespace MySQL
{
	void Connect(std::string ip, std::string login, std::string password, std::string db, unsigned int port);
	void ExecuteQuery(std::string query);
	void SetDatabase(std::string database);
}
