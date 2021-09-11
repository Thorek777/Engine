#include "Log.hpp"
#include "MySQL.hpp"

int err = 0;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
std::string conf_ip, conf_login, conf_password, conf_db;
unsigned int conf_port;

namespace MySQL
{
	void Connect(std::string ip, std::string login, std::string password, std::string db, unsigned int port)
	{
		conf_ip = ip;
		conf_login = login;
		conf_password = password;
		conf_db = db;
		conf_port = port;

		if (conn != 0)
		{
			Log::Send(0, "MySQL has been restared.");
			mysql_close(conn);
		}

		conn = mysql_init(0);

		if (!mysql_real_connect(conn, ip.c_str(), login.c_str(), password.c_str(), db.c_str(), port, NULL, 0))
		{
			Log::Send(1, "Unable to connect with MySQL.");
			exit(1);
		}
	}

	void ExecuteQuery(std::string query)
	{
		err = mysql_query(conn, query.c_str());
		res = mysql_store_result(conn);
		std::string err2 = mysql_error(conn);

		if (query.find("select") != std::string::npos)
		{
			if (!res)
			{
				Log::Send(1, "An error has ocurred, code: " + err2 + ".");
				exit(1);
			}

			uint64_t total_rows = mysql_num_rows(res);

			if (err != 0)
			{
				goto end;
			}
		}
		else
		{
			if (err != 0)
			{
			end:
				Log::Send(1, "Failed to send query. Error code: " + err2 + ".");
				exit(1);
			}
		}
	}

	void SetDatabase(std::string current_db)
	{
		if (current_db != conf_db)
		{
			MySQL::Connect(conf_ip, conf_login, conf_password, current_db, conf_port);
		}
	}
}
