#include "../Includes.h"

void MySQL_Connect(const char* host, const char* user, const char* passwd, const char* db, unsigned int port, const char* unix_socket, unsigned long clientflag, string query)
{
	int qstate;
	MYSQL* conn;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "core", 3306, NULL, 0);
	if (conn)
	{
		cout << "Successful connection to database!" << "\n \n";

		if (query.length() > 0)
		{
			const char* q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
				res = mysql_store_result(conn);
			else
				cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		cout << "Connection to database has failed!" << "\n \n";
	}
}
