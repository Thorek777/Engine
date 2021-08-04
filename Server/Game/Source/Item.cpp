#include <iostream>

#include "Utils/MySQL/MySQL_Func.h"
#include "Item.hpp"

std::vector<int> item;

namespace Item
{
	void Load()
	{
		MySQL::SetDatabase("player");
		MySQL::ExecuteQuery("select * from item_proto");

		// This should be remembered:
		// row[0] - id;
		// row[1] - name;
		while (row = mysql_fetch_row(res))
		{
			int row0 = atoi(row[0]);
			item.push_back(row0);

			// for (int i = 0; i < item.size(); i++)
				// std::cout << item[i] << std::endl;
		}
	}
}
