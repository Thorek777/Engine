#include "../../Common/Namespaces.hpp"
#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

void LoadItem()
{
	base = "player";
	MySQL_ExecuteQuery("select * from item_proto");

	while (row = mysql_fetch_row(res2))
	{
		int row0 = atoi(row[0]);
		item.push_back(row0);

		// for (int i = 0; i < item.size(); i++)
			// cout << item[i] << endl;
	}

	MySQL_Clear();
}
