#pragma once

MYSQL* conn = mysql_init(0);
MYSQL_ROW row;
MYSQL_RES* res;
const char* database;

namespace MySQL
{
	void Connect(const char* host, const char* login, const char* password, int port);
	void ExecuteQuery(std::string query);
	void SetDatabse(const char* current_database);
	void Clear();
}
