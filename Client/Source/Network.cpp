#include <string>
#include <iostream>
#include <WS2tcpip.h>
#include "Network.hpp"

#pragma comment (lib, "ws2_32.lib")

namespace Network
{
	int OpenConnection()
	{
		WSADATA data;
		constexpr WORD version = MAKEWORD(2, 2);

		if (const int ws_ok = WSAStartup(version, &data); ws_ok == 0)
		{
			sockaddr_in server{};
			// int server_length = sizeof(server);
			server.sin_family = AF_INET;
			server.sin_port = htons(54000);
			inet_pton(AF_INET, "192.168.0.111", &server.sin_addr);
			const SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
			std::string s;
			char buf[1024] = { 0 };

			do
			{
				std::cout << "> ";
				std::getline(std::cin, s);

				if (!s.empty())
				{
					if (const int send_ok = sendto(out, s.c_str(), s.size() + 1, 0, reinterpret_cast<sockaddr*>(&server), sizeof(server)); send_ok != SOCKET_ERROR)
					{
						//	if (s[0] == '/')
						//	{
						//		if (const int bytes_in = recvfrom(out, buf, 1024, 0, reinterpret_cast<sockaddr*>(&server), &server_length); bytes_in > 0)
						//			std::cout << buf << '\n';
						//	}
					}
					else
					{
						std::cout << "That didn't work! (" << WSAGetLastError() << ")." << '\n';
						std::memset(buf, 0, 1024);
						closesocket(out);
						WSACleanup();
						return 1;
					}
				}
			} while (!s.empty());

			closesocket(out);
			WSACleanup();
		}
		else
		{
			std::cout << "Can't start Winsock! (" << ws_ok << ").";
			return 1;
		}

		return 0;
	}
}
