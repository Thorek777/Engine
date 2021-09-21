#include <algorithm>

#include "Log.hpp"
#include "Item.hpp"
#include "MySQL.hpp"

void CreateItem(const int id, const int quantity)
{
	if (!std::ranges::count(item_proto, id))
	{
		std::cout << "Item not found." << "\n";
		return;
	}

	MySQL::SetDatabase("player");
	MySQL::ExecuteQuery(
		"insert into item_player (id, count) values ('" + std::to_string(id) + "', '" + std::to_string(quantity) +
		"')");
	Log::Send(0, "Created new item. ID: " + std::to_string(id) + ", Count: " + std::to_string(quantity) + ".");
}
