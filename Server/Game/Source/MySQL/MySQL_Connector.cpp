#include "../../../Common/Include.hpp"

void MySQL_ExecuteQuery(string query)
{
	MYSQL* conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "core", 3306, NULL, 0);
	if (conn)
	{
		SendLog(0, "Successfully connected with database!");

		if (query.length() > 0)
		{
			int qstate = mysql_query(conn, query.c_str());
			if (!qstate)
			{
				MYSQL_RES* res = mysql_store_result(conn);
				res2 = res;
				SendLog(0, "Query has been sent (" + query + ")!");
			}
			else
			{
				string error = mysql_error(conn);
				SendLog(1, "Query hasn't been sent: " + error + ".");
				exit(0);
			}
		}
	}
	else
	{
		SendLog(1, "Connection with database was failed.");
		exit(0);
	}
}
