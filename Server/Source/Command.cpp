/*
 * Author: Thorek
 */

#include <iostream>
#include <algorithm>

#include "Log.h"
#include "Item.h"
#include "MySQL.h"

void CreateItem(const int id, const int quantity)
{
	if (!count(item_proto.begin(), item_proto.end(), id))
	{
		std::cout << "Item not found." << "\n";
		return;
	}

	MySQL::SetDatabase("player");
	MySQL::ExecuteQuery("insert into item (id, count) values ('" + std::to_string(id) + "', '" + std::to_string(quantity) + "')");
	Log::Send(0, "Created new item. ID: " + std::to_string(id) + ", Count: " + std::to_string(quantity) + ".");
}
