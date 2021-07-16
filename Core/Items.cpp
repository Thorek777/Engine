#include "Includes.h"

void CreateItem(string id, string count)
{
	int qstate;
	MYSQL* conn;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_BASE, 3306, NULL, 0);
	if (conn)
	{
		string query = "insert into items (id, count) VALUES ('" + id + "', '" + count + "')";
		qstate = mysql_query(conn, query.c_str());
		if (!qstate)
			res = mysql_store_result(conn);
		else
			cout << "Query failed: " << mysql_error(conn) << endl;
	}
	else
	{
		cout << "Connection to database has failed!";
	}
}
