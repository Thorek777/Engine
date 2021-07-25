#include <iostream>

#include "Utils/MySQL/MySQL_Func.h"
#include "Utils/Log.hpp"
#include "Command.hpp"
#include "Item.hpp"

RegisterNewCommand CreateItem(int id, int count)
{
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
