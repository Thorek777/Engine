/*
 * Author: Thorek
 * Currently, this file has been created for test purposes.
 */

#include <iostream>

namespace Character
{
	int Move(const int x, const int y)
	{
		if (x > 0 || y > 0)
		{
			std::cout << "x: " << x << ", y: " << y << '\n' << '\n';
		}

		return 0;
	}
}
