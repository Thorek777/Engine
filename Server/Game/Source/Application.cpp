#include "Utils/MySQL/MySQL_Func.hpp"
#include "Utils/Log.hpp"

#define Start main

struct Deleter
{
	void operator()(MYSQL_RES* res2)
	{
		mysql_free_result(res2);
	}
};

using unique_res = std::unique_ptr<MYSQL_RES, Deleter>;

int Start()
{
	DeleteLog();

	MYSQL_ROW row2;
	MySQL::Connect("127.0.0.1", "root", "", "account", 3307);
	mysql_query(conn, "select * from account");
	unique_res res2(nullptr);
	res2.reset(mysql_store_result(conn));

	while (row = mysql_fetch_row(res2.get()))
	{
		std::cout << row[1] << "\n";
	}

	MySQL::ExecuteQuery("select * from account");

	while (row2 = mysql_fetch_row(res))
	{
		std::cout << row2[1] << "\n";
	}

	return 0;
}
