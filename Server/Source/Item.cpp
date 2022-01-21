#include <vector>
#include <iostream>
#include <algorithm>

#include "Item.h"
#include "MySQL.h"

std::vector<int> item_proto;

namespace Item
{
	void Load()
	{
		// Set database to player:
		MySQL::SetDatabase("player");

		// Select ALL from item_proto:
		MySQL::ExecuteQuery("select * from item_proto");

		// And insert data from query to item_proto vector.
		while (row == mysql_fetch_row(res))
			item_proto.emplace_back(strtol(row[0], nullptr, 0));
	}

	void CheckForExistence(const int id)
	{
		// Checks if in item_proto vector is id from this function variable:
#ifdef _WIN32 // std::ranges::count is don't work properly on Linux (i don't know why), so i created #ifdef.
		if (!std::ranges::count(item_proto, id))
#else
		if (!count(item_proto.begin(), item_proto.end(), id))
#endif
		{
			std::cout << "Item not found." << "\n";
		}
	}
}
