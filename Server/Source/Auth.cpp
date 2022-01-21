/*
 * Todo - Make password encryption (MD5 or something).
 * Todo - Add sending information about success login to Client.
 */

#include "Log.h"
#include "Auth.h"
#include "MySQL.h"

namespace Auth
{
	int Login(const std::string& login, const std::string& password)
	{
		// Set current database to account:
		MySQL::SetDatabase("account");

		// Execute query which select login and password from account table:
		MySQL::ExecuteQuery("select login, password from account");

		// Check if row[0] (login) and row[1] (password) is equal to variables in this function:
		bool status = false;

		while ((row = mysql_fetch_row(res)))
			if (login == row[0] && password == row[1])
			{
				// If yes, set status to true and get out of loop:
				status = true;
				break;
			}

		// If status isn't true:
		if (!status)
		{
			Log::Send(0, "Login step hasn't been completed successfully by: " + login + ".");
			return 1;
		}

		// Else, if status IS true:
		Log::Send(0, "Login step has been completed successfully by: " + login + ".");
		return 0;
	}
}
