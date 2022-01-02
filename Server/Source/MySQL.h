#pragma once

#include <string>
#include <mysql.h>

extern MYSQL* conn;
extern MYSQL_ROW row;
extern MYSQL_RES* res;

namespace MySQL
{
    int Connect(const std::string& ip,
                const std::string& login,
                const std::string& password,
                const std::string& db,
                unsigned int port);

    int ExecuteQuery(const std::string& query);
    void SetDatabase(const std::string& current_db);
}
