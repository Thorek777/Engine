#include "../../Common/Namespaces.hpp"
#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

void Login(string login, string password)
{
	base = "account";
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
			SendLog(0, "Login step has been completed successfully. Login: " + login + ".");
		}
	}

	MySQL_Clear();
}
