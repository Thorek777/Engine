#include "../../../../Common/Namespaces.hpp"
#include "../../../../Common/D_Includes.hpp"
#include "../../../../Common/O_Includes.hpp"

void MySQL_ExecuteQuery(string query)
{
	MYSQL* conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", base, 3306, NULL, 0);
	if (conn)
	{
		SendLog(0, "Successfully connected with database!");

		if (query.length() > 0)
		{
			int qstate = mysql_query(conn, query.c_str());
			if (!qstate)
			{
				int total_rows = 0;
				MYSQL_RES* res = mysql_store_result(conn);
				total_rows = mysql_num_rows(res);
				if (total_rows == 0)
				{
					SendLog(1, "NullPointer detected! Caused by: MYSQL_RES* res.");
					exit(0);
				}
				else
				{
					res2 = res;
					SendLog(0, "Query has been sent (" + query + ")!");
				}
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

void MySQL_Clear()
{
	if (res2 != 0)
		res2 = 0;

	if (base != 0)
		base = 0;
}
