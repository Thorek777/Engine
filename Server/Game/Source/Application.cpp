#include "Utils/MySQL/MySQL_Func.h"
#include "Utils/Log.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Auth.hpp"

bool CleanUp()
{
	if (remove("N-Log.txt") == 0 || (remove("E-Log.txt") == 0))
		return true;
	else
		return false;
}

#define Start main

int Start()
{
	CleanUp();
	// MySQL::Connect("127.0.0.1", 3306, "root", "", "account");
	// GetPlayerPrivileges();
	// LoadItem(); // Must be before CreateItem function!
	// Login("Test", "1234");
	// CreateItem(19, 1);
	return 0;
}
