#include <iostream>
#include "Config.h"
#include "Network.h"

sockaddr_in server2;
unsigned long long out2;

namespace Network
{
	int StartWinsock()
	{
		WSADATA data;
		constexpr WORD version = MAKEWORD(2, 2);

		if (const int ws_ok = WSAStartup(version, &data); ws_ok != 0)
		{
			std::cout << "Can't start Winsock! (" << ws_ok << ").";
			return 1;
		}

		return 0;
	}

	int OpenConnection()
	{
		sockaddr_in server{};
		server.sin_family = AF_INET;
		server.sin_port = htons(SERVER_PORT);
		inet_pton(AF_INET, SERVER_IP, &server.sin_addr);
		server2 = server;
		const SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
		out2 = out;
		return 0;
	}
}
