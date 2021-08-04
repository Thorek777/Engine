#include <iostream>
#include <sstream>
#include <string>

#include "Utils/MySQL/MySQL_Func.hpp"

namespace Player
{
	int GetCharCount(std::string n)
	{
		MYSQL_ROW local_row;
		int count = 0;

		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from player");

		while (local_row = mysql_fetch_row(res))
		{
			if (local_row[0] == n)
				count++;
		}

		return count;
	}

	int GetPrivilege()
	{
		return 0;
	}
}
