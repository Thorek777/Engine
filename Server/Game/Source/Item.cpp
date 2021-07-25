#include <iostream>

#include "Utils/MySQL/MySQL_Func.h"
#include "Item.hpp"

std::vector<int> item;

void LoadItem()
{
	if (conf_db != "player")
		MySQL::SetDatabase("player");

	MySQL::ExecuteQuery("select * from item_proto");

	while (row = mysql_fetch_row(res))
	{
		int row0 = atoi(row[0]);
		item.push_back(row0);

		// for (int i = 0; i < item.size(); i++)
			// std::cout << item[i] << std::endl;
	}
}
