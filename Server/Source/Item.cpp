#include "Item.hpp"
#include "MySQL.hpp"

std::vector<int> item_proto;

namespace Item
{
	void Load()
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from item_proto");

		while (row = mysql_fetch_row(res))
		{
			int row0 = atoi(row[0]);
			item_proto.push_back(row0);
		}
	}
}
