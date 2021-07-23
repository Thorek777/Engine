#include "../../Common/Include.hpp"

// To do: MD5 security for passwords.

void Login(string login, string password)
{
	MySQL_ExecuteQuery("select login, password from account");

	while (row = mysql_fetch_row(res2))
	{
		if (!row[0] || !row[1]) // Protection against Core crash (NULL).
			goto end;

		if (login != row[0] || password != row[1])
		{
		end:
			cout << "Login or password isn't correct." << "\n";
			return;
		}
		else
		{
			cout << "Login and password is correct." << "\n";
		}
	}

	res2 = 0;
	SendLog(0, "Login step has been completed successfully. Login: " + login + ".");
}
