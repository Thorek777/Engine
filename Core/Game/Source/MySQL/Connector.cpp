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
		cout << "Successfully connected with database." << "\n";

		if (query.length() > 0)
		{
			qstate = mysql_query(conn, query.c_str());
			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << "Query has been sent!" << "\n \n";
			}
			else
			{
				cout << "Query hasn't been sent: " << mysql_error(conn) << "\n \n";
			}
		}
		else
		{
			cout << "Query doesn't exist!" << "\n \n";
		}
	}
	else
	{
		cout << "Connection with database was failed." << "\n \n";
	}
}
