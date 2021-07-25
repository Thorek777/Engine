#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

RegisterNewCommand CreateItem(int id, int count)
{
	if (!id || !count)
		return;

	// If ID isn't found in loaded items vector, item will not be created:
	if (!std::count(item.begin(), item.end(), id))
	{
		std::cout << "Item not found.";
		return;
	}

	auto id_s = std::to_string(id);
	auto count_s = std::to_string(count);

	MySQL::SetDatabse("player");
	MySQL::ExecuteQuery("insert into item (id, count) values ('" + id_s + "', '" + count_s + "')");
	MySQL::Clear();

	SendLog(0, "Created new item. ID: " + id_s + ", Count: " + count_s + ".");
}
