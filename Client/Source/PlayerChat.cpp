/*
 * Author: Thorek
 */

#include <string>
#include <iostream>
#include "Network.h"
#include "InputKeyboard.h"

#pragma comment (lib, "ws2_32.lib")

namespace Player::Chat
{
	int Open()
	{
		std::cout << "Chat has been opened." << '\n' << '\n';
		ClearKeyboardBuffer();
		std::string message;
		char buf[1024] = { 0 };

		do
		{
			std::cout << "> ";
			std::getline(std::cin, message);

			if (message.empty())
			{
				std::cout << '\n' << "Message can't be empty!" << '\n';
				return 1;
			}

			if (const int send_ok = Network::SendPacket(message); send_ok == SOCKET_ERROR)
			{
				std::cout << "That didn't work! (" << WSAGetLastError() << ")." << '\n';
				std::memset(buf, 0, 1024);
				closesocket(out2);
				WSACleanup();
				return 1;
			}
		} while (!message.empty());

		closesocket(out2);
		WSACleanup();
		return 0;
	}
}
