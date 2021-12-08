#include "Log.h"
#include "MySQL.h"

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
std::string config[4];
unsigned int config_port;

namespace MySQL
{
	int Connect(const std::string& ip, const std::string& login, const std::string& password, const std::string& db, const unsigned int port)
	{
		config[0] = ip;
		config[1] = login;
		config[2] = password;
		config[3] = db;
		config_port = port;

		if (conn != nullptr)
			mysql_close(conn);

		conn = mysql_init(nullptr);

		if (mysql_real_connect(conn, ip.c_str(), login.c_str(), password.c_str(), db.c_str(), port, nullptr, 0) == nullptr)
		{
			Log::Send(1, "Unable to connect with MySQL.");
			exit(1);
		}

		return 0;
	}

	int ExecuteQuery(const std::string& query)
	{
		const int err = mysql_query(conn, query.c_str());
		res = mysql_store_result(conn);
		const std::string err2 = mysql_error(conn);

		if (query.find("select") != std::string::npos)
		{
			if (res == nullptr)
			{
				Log::Send(1, "An error has occurred, code: " + err2 + ".");
				return 1;
			}
		}

		if (err != 0)
		{
			Log::Send(1, "Failed to send query. Error code: " + err2 + ".");
			return 1;
		}

		return 0;
	}

	void SetDatabase(const std::string& current_db)
	{
		if (current_db != config[3])
			Connect(config[0], config[1], config[2], current_db, config_port);
	}
}
