#include "Log.hpp"
#include "Auth.hpp"
#include "MySQL.hpp"

namespace Auth
{
	int Login(const std::string& login, const std::string& password)
	{
		if (auth_status)
		{
			std::cout << "You have already been logged in!";
			return 1;
		}

		MySQL::SetDatabase("account");
		MySQL::ExecuteQuery("select login, password from account");

		while (row == mysql_fetch_row(res))
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

		Log::Send(0, "Login step has been completed successfully. Login: " + login + ".");
		return 0;
	}
}
