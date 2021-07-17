#include "../../../Common/Includes.hpp"

void MySQL_ExecuteQuery(string query)
{
	int qstate;
	MYSQL* conn;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_BASE, 3306, NULL, 0);
	if (conn)
	{
		SendLog(0, "Successfully connected with database.");

		if (query.length() > 0)
		{
			qstate = mysql_query(conn, query.c_str());
			if (!qstate)
			{
				res = mysql_store_result(conn);
				SendLog(0, "Query has been sent!");
			}
			else
			{
				string error = mysql_error(conn);
				SendLog(1, "Query hasn't been sent: " + error + ".");
			}
		}
		else
		{
			SendLog(1, "Query doesn't exist!");
			exit(0);
		}
	}
	else
	{
		SendLog(1, "Connection with database was failed.");
		exit(0);
	}
}
