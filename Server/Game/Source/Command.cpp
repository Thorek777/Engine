#include <iostream>

#include "Utils/MySQL/MySQL_Func.h"
#include "Utils/Log.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include "Item.hpp"

RegisterNewCommand CreateItem(int id, int count)
{
	// If player (currently account) doesn't have at least third level of the permission:
	if (GetPlayerPrivileges() < 3)
	{
		std::cout << "\n" << "You don't have enough permission." << "\n";
		return;
	}

	if (!id || !count)
		return;

	// If ID isn't found in loaded items vector, item will not be created:
	if (!std::count(item.begin(), item.end(), id))
	{
		std::cout << "Item not found." << "\n";
		return;
	}

	if (conf_db != "player")
		MySQL::SetDatabase("player");

	MySQL::ExecuteQuery("insert into item_player (id, count) values ('" + std::to_string(id) + "', '" + std::to_string(count) + "')");
	SendLog(0, "Created new item. ID: " + std::to_string(id) + ", Count: " + std::to_string(count) + ".");
}
