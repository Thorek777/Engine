#include <iostream>
#include <sstream>
#include <string>

#include "Utils/MySQL/MySQL_Func.h"

//
// To do: Fix searching e.g. 2 entries in a table:
// 1 1 Thorek  <- Entry that will be found (in player table).
// 1 2 Thorek2 <- Entry that not will be found (in player table).
//

bool IsPlayerExistOnAccount(std::string login)
{
	// So, we choose "player" database to retrieve data from table with the same name:
	MySQL::SetDatabase("player");
	MySQL::ExecuteQuery("select * from player");

	// This should be remembered:
	// row[0] - account_id;
	// row[1] - player_id;
	// row[2] - name.
	while (row = mysql_fetch_row(res))
	{
		if (!row[0] || !row[1] || !row[2]) // Protection against NullPointer.
			return false;

		std::string row0_player = row[0]; // We save account_id to string variable.
		std::string row2_player = row[2]; // We save name to string variable.

		// And next, we choose "account" database to retrieve data from table with the same name:
		MySQL::SetDatabase("account");
		MySQL::ExecuteQuery("select * from account");

		// This should be remembered:
		// row[0] - id;
		// row[1] - login;
		// row[2] - password.
		while (row = mysql_fetch_row(res))
		{
			if (!row[0] || !row[1] || !row[2]) // Protection against NullPointer.
				return false;

			std::string row0_account = row[0]; // We save id to string variable.
			std::string row1_account = row[1]; // We save login to string variable.
			if (row0_player == row0_account && login == row1_account)
			{
				std::cout << "On given account there is a character named: " << row2_player << "\n";
				return true;
			}
			else
			{
				std::cout << "ERROR!" << "\n";
				break;
			}
		}
	}
}

int GetPlayerPrivilege()
{
	// So, we choose "player" database to retrieve data from table with the same name:
	MySQL::SetDatabase("account");
	MySQL::ExecuteQuery("select * from privilege");

	// This should be remembered:
	// row[0] - account_name;
	// row[1] - privilege;
	while (row = mysql_fetch_row(res))
	{
		if (!row[0] || !row[1]) // Protection against NullPointer.
			break;

		std::string row0_account = row[0]; // We save account_name to string variable.
		int row1_account = atoi(row[1]); // We save privilege to int variable.

		// We are still in the "account" database so we just have to switch to another table:
		MySQL::ExecuteQuery("select * from account");

		// This should be remembered:
		// row[0] - id;
		// row[1] - login;
		// row[2] - password.
		while (row = mysql_fetch_row(res))
		{
			if (!row[0] || !row[1]) // Protection against NullPointer.
				break;

			std::string row1_account_name = row[1]; // We save login to string variable.
			if (row0_account == row1_account_name)
			{
				switch (row1_account)
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
				break;
			}
		}
	}
}
