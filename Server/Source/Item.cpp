#include "Item.h"
#include "MySQL.h"

std::vector<int> item_proto;

namespace Item
{
	void Load()
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from item_proto");

		while (row == mysql_fetch_row(res))
			item_proto.push_back(strtol(row[0], nullptr, 0));
	}
}
