#include <array>
#include <vector>
#include <iostream>
#include <WS2tcpip.h>

#include "Log.hpp"
#include "Auth.hpp"

#pragma comment (lib, "ws2_32.lib")

enum class PACKET_TYPES
{
	WRONG_PACKET,
	AUTH_LOGIN,
};

PACKET_TYPES GetPacket(std::string command)
{
	if (command == "login")
	{
		return PACKET_TYPES::AUTH_LOGIN;
	}

	return PACKET_TYPES::WRONG_PACKET;
}

namespace Network
{
	int Test()
	{
		WSADATA data;
		WORD version = MAKEWORD(2, 2);
		int ws_ok = WSAStartup(version, &data);

		if (ws_ok != 0)
		{
			Log::Send(1, "Can't start Winsock! " + ws_ok);
			return 1;
		}

		SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
		sockaddr_in server_hint;
		server_hint.sin_addr.S_un.S_addr = ADDR_ANY;
		server_hint.sin_family = AF_INET;
		server_hint.sin_port = htons(54000);

		if (bind(in, (sockaddr*)&server_hint, sizeof(server_hint)) == SOCKET_ERROR)
		{
			Log::Send(1, "Can't bind socket! " + WSAGetLastError());
			return 1;
		}

		sockaddr_in client;
		int client_length = sizeof(client);
		char buf[1024] = { 0 };
		std::string text_1;
		std::array<std::string, 3> costam;

		while (true)
		{
			ZeroMemory(&client, client_length);
			ZeroMemory(buf, 1024);
			int bytes_in = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &client_length);

			if (bytes_in == SOCKET_ERROR)
			{
				Log::Send(1, "Error receiving from client: " + WSAGetLastError());
				continue;
			}

			char client_ip[256];
			ZeroMemory(client_ip, 256);
			inet_ntop(AF_INET, &client.sin_addr, client_ip, 256);

			std::string gowno = client_ip;
			std::string gowno2 = buf;
			Log::Send(0, "Message recv from: " + gowno + ", " + gowno2);

			if (buf[0] == '/')
			{
				int i = 0;
				int j = 0;

				while (buf[++i] != '\0')
				{
					if (buf[i] != ' ' && buf[i] != ';')
					{
						text_1 += buf[i];
					}
					else
					{
						costam[j] = text_1;
						text_1 = "";

						if (j != 2)
						{
							j++;
						}
					}
				}

				switch (GetPacket(costam[0]))
				{
					case PACKET_TYPES::AUTH_LOGIN:
					{
						// std::cout << costam[1] << '\n';
						// std::cout << costam[2] << '\n';

						if (costam[1] != "" && costam[2] != "")
						{
							Auth::Login(costam[1], costam[2]);
							costam[0] = "";
							costam[1] = "";
							costam[2] = "";
						}
					}
					break;

					case PACKET_TYPES::WRONG_PACKET:
					{
						costam[0] = "";
						costam[1] = "";
						costam[2] = "";
					}
					break;
				}
			}
		}

		closesocket(in);
		WSACleanup();
	}
}
