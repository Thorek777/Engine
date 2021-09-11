#include <string>
#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

namespace Network
{
	int OpenConnection()
	{
		WSADATA data;
		WORD version = MAKEWORD(2, 2);
		int ws_ok = WSAStartup(version, &data);

		if (ws_ok == 0)
		{
			sockaddr_in server;
			int server_length = sizeof(server);
			server.sin_family = AF_INET;
			server.sin_port = htons(54000);
			inet_pton(AF_INET, "192.168.0.111", &server.sin_addr);
			SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
			std::string s;
			char buf[1024] = { 0 };
			int bytes_in;

			do
			{
				std::cout << "> ";
				std::getline(std::cin, s);

				if (s.size() > 0)
				{
					int send_ok = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));

					if (send_ok != SOCKET_ERROR)
					{
						if (s[0] == '/')
						{
							bytes_in = recvfrom(out, buf, 1024, 0, (sockaddr*)&server, &server_length);

							if (bytes_in > 0)
							{
								std::cout << buf << '\n';
							}

							//	if (bytes_in == SOCKET_ERROR)
							//	{
							//		std::cout << "That didn't work! " << WSAGetLastError() << '\n';
							//		std::memset(buf, 0, 1024);
							//		closesocket(out);
							//		WSACleanup();
							//		return 1;
							//	}
							//	else
							//	{
							//		std::cout << buf << '\n';
							//	}
						}
					}
					else
					{
						std::cout << "That didn't work! " << WSAGetLastError() << '\n';
						std::memset(buf, 0, 1024);
						closesocket(out);
						WSACleanup();
						return 1;
					}
				}
			} while (s.size() > 0);

			closesocket(out);
			WSACleanup();
		}
		else
		{
			std::cout << "Can't start Winsock! " << ws_ok;
			return 1;
		}

		return 0;
	}
}
