#include <iostream>

#include "Item.hpp"
#include "MySQL.hpp"

std::vector<int> item_proto_item;

namespace Item
{
	void Load()
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from item_proto");

		// row[0] = id,
		// row[1] = name.
		while (row = mysql_fetch_row(res))
		{
			int row0 = atoi(row[0]);
			item_proto_item.push_back(row0);
		}
	}
}
