#include "Utils/MySQL/MySQL_Func.h"
#include "Utils/Log.hpp"

namespace Auth
{
	void Login(std::string login, std::string password)
	{
		MySQL::SetDatabase("account");
		MySQL::ExecuteQuery("select login, password from account");

		// This should be remembered:
		// row[0] - id;
		// row[1] - login;
		// row[2] - password.
		while (row = mysql_fetch_row(res))
		{
			if (!row[0] || !row[1])
			{
				SendLog(1, "NullPointer detected! Caused by: Login function (empty row[0] or row[1]).");
				goto end;
			}

			if (login != row[0] || password != row[1])
			{
			end:
				std::cout << "Login or password isn't correct." << "\n";
				return;
			}
			else
			{
				std::cout << "Login and password is correct." << "\n";
				SendLog(0, "Login step has been completed successfully. Login: " + login + ".");
			}
		}
	}
}
