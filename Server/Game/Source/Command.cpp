#include "../../Common/Include.hpp"

RegisterNewCommand CreateItem(int id, int count)
{
	if (!id || !count)
		return;

	auto id_s = to_string(id);
	auto count_s = to_string(count);
	MySQL_ExecuteQuery("insert into items (id, count) values ('" + id_s + "', '" + count_s + "')");
	SendLog(0, "Created new item. ID: " + id_s + ", Count: " + count_s + ".");
}
