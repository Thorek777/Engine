/*
#include "MySQL.hpp"

namespace Player
{
	int GetCharCount(const std::string n)
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from player");
		MYSQL_ROW local_row;
		int count = 0;

		while (local_row = mysql_fetch_row(res))
		{
			if (local_row[0] == n)
			{
				count++;
			}
		}

		return count;
	}
}
*/
