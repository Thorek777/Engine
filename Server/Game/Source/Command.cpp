#include "../../Common/Namespaces.hpp"
#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

RegisterNewCommand CreateItem(int id, int count)
{
	base = "player";
	if (!id || !count)
		return;

	// If ID isn't found in loaded items vector, item will not be created:
	if (!std::count(item.begin(), item.end(), id))
	{
		cout << "Item not found.";
		return;
	}

	auto id_s = to_string(id);
	auto count_s = to_string(count);
	MySQL_ExecuteQuery("insert into item (id, count) values ('" + id_s + "', '" + count_s + "')");
	MySQL_Clear();
	SendLog(0, "Created new item. ID: " + id_s + ", Count: " + count_s + ".");
}
