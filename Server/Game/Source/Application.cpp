#include "Utils/MySQL/MySQL_Func.h"
#include "Utils/Log.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Auth.hpp"

#define Start main

int Start()
{
	CleanUpLog();
	MySQL::Connect("127.0.0.1", 3306, "root", "", "account");
	IsPlayerExistOnAccount("Thorek");
	return 0;
}
