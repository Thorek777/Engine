#include "Log.h"
#include "Item.h"
#include "MySQL.h"

void CreateItem(const int id, const int quantity)
{
	// Use CheckForExistence function to check if item exist in Database:
	Item::CheckForExistence(id);

	// If yes, set Database to player:
	MySQL::SetDatabase("player");

	// Execute query which insert data to item table:
	MySQL::ExecuteQuery("insert into item (id, count) values ('" + std::to_string(id) + "', '" + std::to_string(quantity) + "')");

	// And send log to output:
	Log::Send(0, "Created new item. Id: " + std::to_string(id) + ", Count: " + std::to_string(quantity) + ".");

#ifdef _WIN32
	std::cout << "Created new item. Id: " + std::to_string(id) + ", Count: " + std::to_string(quantity) + "." << '\n';
#endif
}
