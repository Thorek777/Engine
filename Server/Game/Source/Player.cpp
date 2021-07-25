#include <iostream>
#include <sstream>
#include <string>

#include "Utils/MySQL/MySQL_Func.h"

int GetPlayerPrivileges()
{
	MySQL::SetDatabase("account");
	MySQL::ExecuteQuery("select * from privileges");

	while (row = mysql_fetch_row(res))
	{
		std::string row0_account_name = row[0];
		int row1_privilege = atoi(row[1]);

		MySQL::ExecuteQuery("select * from account");

		while (row = mysql_fetch_row(res))
		{
			std::string row1_account_name = row[1];
			if (row0_account_name == row1_account_name)
			{
				std::cout << "Account name (in privileges table) == Account name (in account table).";

				switch (row1_privilege)
				{
				case 1: // PLAYER.
					return 1;

				case 2: // GAME MASTER.
					return 2;

				case 3: // BETTER GAME MASTER.
					return 3;

				case 4: // BETTER BETTER GAME MASTER.
					return 4;

				case 5: // BETTER BETTER BETTER GAME MASTER.
					return 5;
				}
				break;
			}
			else
			{
				std::cout << "Account name (in account table) != Account name (in privileges table).";
				break;
			}
		}
	}
}
