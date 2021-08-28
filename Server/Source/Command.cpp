#include "Log.hpp"
#include "Item.hpp"
#include "MySQL.hpp"

void CreateItem(int id, int count)
{
	if (!std::count(item_proto_item.begin(), item_proto_item.end(), id))
	{
		std::cout << "Item not found." << "\n";
		return;
	}

	MySQL::SetDatabase("player");
	MySQL::ExecuteQuery("insert into item_player (id, count) values ('" + std::to_string(id) + "', '" + std::to_string(count) + "')");
	Log::Send(0, "Created new item. ID: " + std::to_string(id) + ", Count: " + std::to_string(count) + ".");
}
