#include "Includes.hpp"

RegisterNewCommand GiveMeItem(int id, int count)
{
	if (!id || !count)
	{
		cout << "First or second argument wasn't given." << "\n";
		return;
	}

	auto id_s = to_string(id);
	auto count_s = to_string(count);
	CreateItem(id_s, count_s);
}
