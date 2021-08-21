#include "Log.hpp"
#include "MySQL.hpp"

namespace Auth
{
	int Login(std::string login, std::string password)
	{
		MySQL::SetDatabase("account");
		MySQL::ExecuteQuery("select login, password from account");
		bool auth_status = false;

		// row[0] - id;
		// row[1] - login;
		// row[2] - password.
		while (row = mysql_fetch_row(res))
		{
			if (login == row[0] && password == row[1])
			{
				auth_status = true;
				break;
			}
		}

		if (!auth_status)
		{
			return 1;
		}
		else
		{
			Log::Send(0, "Login step has been completed successfully. Login: " + login + ".");
			return 0;
		}
	}
}
