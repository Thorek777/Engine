#include "MySQL_Func.h"
#include "../Log.hpp"

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

std::string conf_ip;
unsigned int conf_port;
std::string conf_db;
std::string conf_login;
std::string conf_password;

std::string error = mysql_error(conn);

int err = 0;

namespace MySQL
{
	void Connect(std::string ip, unsigned int port, std::string login, std::string password, std::string db)
	{
		conf_ip = ip;
		conf_port = port;
		conf_login = login;
		conf_password = password;
		conf_db = db;

		if (conn != 0)
		{
			SendLog(0, "MySQL has been restared.");
			mysql_close(conn);
		}

		conn = mysql_init(0);

		if (!mysql_real_connect(conn, ip.c_str(), login.c_str(), password.c_str(), db.c_str(), port, NULL, 0))
		{
			error = mysql_error(conn);
			SendLog(1, "Connection with database was failed: " + error + ".");
			exit(1);
		}
		else
		{
			SendLog(0, "Successfully connected with database!");
		}
	}

	void ExecuteQuery(std::string query)
	{
		err = mysql_query(conn, query.c_str());
		res = mysql_store_result(conn);

		if (res != 0) // Protection against NullPointer.
		{
			int total_rows = 0;
			total_rows = mysql_num_rows(res);
			if (total_rows != 0) // If total rows isn't 0.
			{
				if (err)
				{
					error = mysql_error(conn);
					SendLog(1, "Query execute failed:" + error + ".");
					mysql_free_result(res);
					exit(1);
				}
				else
				{
					SendLog(0, "Query has been sent (" + query + ")!");
				}
			}
			else
			{
				SendLog(1, "Query has been sent: (" + query + ") but its value is 0.");
				exit(0);
			}
		}
		else
		{
			exit(1);
		}
	}

	void SetDatabase(std::string current_db)
	{
		MySQL::Connect(conf_ip, conf_port, conf_login, conf_password, current_db);
	}
}
