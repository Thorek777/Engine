#include "Includes.hpp"

void GiveMeItem(int id, int count)
{
	if (!id)
	{
		cout << "First argument wasn't given." << "\n";
		return;
	}

	if (!count)
	{
		cout << "Second argument wasn't given." << "\n";
		return;
	}

	auto id_s = to_string(id);
	auto count_s = to_string(count);
	CreateItem(id_s, count_s);
}
