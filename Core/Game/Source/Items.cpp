#include "../../Common/Includes.hpp"

void CreateItem(string id, string count)
{
	MySQL_ExecuteQuery("insert into items (id, count) VALUES ('" + id + "', '" + count + "')");
	SendLog(0, "CreateItem - ID: " + id + ", Count: " + count + ".");
}
