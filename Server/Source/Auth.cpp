#include "Log.hpp"
#include "Auth.hpp"
#include "MySQL.hpp"

namespace Auth
{
	int Login(const std::string& login, const std::string& password)
	{
		MySQL::SetDatabase("account");
		MySQL::ExecuteQuery("select login, password from account");
		bool status = false;

		while ((row = mysql_fetch_row(res)))
		{
			if (login == row[0] && password == row[1])
			{
				status = true;
				break;
			}
		}

		if (status)
			Log::Send(0, "Login step has been completed successfully by: " + login + ".");
		else
		{
			Log::Send(0, "Login step hasn't been completed successfully by: " + login + ".");
			return 1;
		}

		return 0;
	}
}
