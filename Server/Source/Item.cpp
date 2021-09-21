#include "Item.hpp"
#include "MySQL.hpp"

std::vector<int> item_proto;

namespace Item
{
	void Load()
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from item_proto");

		while (row == mysql_fetch_row(res))
		{
			item_proto.push_back(atoi(row[0]));
		}
	}
}
