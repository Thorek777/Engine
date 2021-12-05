/*
 * Author: Thorek
 * Currently, this file has been created for test purposes.
 */

#include <string>
#include "Network.h"

namespace Character
{
	int Move()
	{
		int x = 0, y = 0;
		srand(time(nullptr));

		while (true)
		{
			if (GetKeyState(VK_UP) & 0x8000)
			{
				x += std::rand() % 10 + 1;
				y += std::rand() % 10 + 1;
				break;
			}
		}

		Network::SendPacket("/move " + std::to_string(x) + " " + std::to_string(y));
		return 0;
	}
}
