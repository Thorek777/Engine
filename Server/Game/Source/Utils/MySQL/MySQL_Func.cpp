#include "MySQL_Func.hpp"
#include "../Log.hpp"

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
std::string conf_ip;
std::string conf_db;
std::string conf_login;
std::string conf_password;
unsigned int conf_port;
std::string error = mysql_error(conn);
int err = 0;

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

		if (res != 0)
		{
			int total_rows = 0;
			total_rows = mysql_num_rows(res);

			if (total_rows != 0)
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
				return;
			}
		}
		else
		{
			exit(1);
		}
	}

	void SetDatabase(std::string current_db)
	{
		if (current_db != conf_db)
			MySQL::Connect(conf_ip, conf_login, conf_password, current_db, conf_port);
	}
}
