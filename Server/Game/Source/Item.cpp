#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

void LoadItem()
{
	MySQL::SetDatabse("player");
	MySQL::ExecuteQuery("select * from item_proto");

	while (row = mysql_fetch_row(res))
	{
		int row0 = atoi(row[0]);
		item.push_back(row0);

		// for (int i = 0; i < item.size(); i++)
			// std::cout << item[i] << endl;
	}

	MySQL::Clear();
}
