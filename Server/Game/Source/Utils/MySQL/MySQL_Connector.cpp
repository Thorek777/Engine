#include "../../../../Common/D_Includes.hpp"
#include "../../../../Common/O_Includes.hpp"

namespace MySQL
{
	void Connect(const char* host, const char* login, const char* password, int port)
	{
		conn = mysql_real_connect(conn, host, login, password, database, port, NULL, 0);
		if (conn)
		{
			SendLog(0, "Successfully connected with database!");
		}
		else
		{
			SendLog(1, "Connection with database was failed.");
			exit(0);
		}
	}

	void ExecuteQuery(std::string query)
	{
		if (conn && query.length() > 0)
		{
			int qstate = mysql_query(conn, query.c_str());
			if (!qstate)
			{
				// int total_rows = 0;
				uint64_t total_rows = 0;
				res = mysql_store_result(conn);
				total_rows = mysql_num_rows(res);
				if (total_rows == 0)
				{
					SendLog(1, "NullPointer detected! Caused by: MYSQL_RES* res.");
					exit(0);
				}
				else
				{
					SendLog(0, "Query has been sent (" + query + ")!");
					// mysql_close(conn);
				}
			}
			else
			{
				std::string error = mysql_error(conn);
				SendLog(1, "Query hasn't been sent: " + error + ".");
				exit(0);
			}
		}
	}

	void SetDatabse(const char* current_database)
	{
		database = current_database;
	}

	void Clear()
	{
		mysql_free_result(res);
	}
}
