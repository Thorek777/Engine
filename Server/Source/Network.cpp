#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment (lib, "ws2_32.lib")
#else
#include <cstring>

#include "../../netdb.h"
#include "../../unistd.h"
#include "../../arpa/inet.h"
#include "../../include/x86_64-linux-gnu/sys/socket.h"
#endif

#include <array>
#include <string>

#include "Log.hpp"
#include "Auth.hpp"

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
	int OpenConnection()
	{
#ifdef _WIN32
		WSADATA data;
		WORD version = MAKEWORD(2, 2);
		int ws_ok = WSAStartup(version, &data);

		if (ws_ok != 0)
		{
			Log::Send(1, "Can't start Winsock! " + ws_ok);
			return 1;
		}
#endif

#ifdef _WIN32
		SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
#else
		int in = socket(AF_INET, SOCK_DGRAM, 0);
#endif
		sockaddr_in server_hint;
#ifdef _WIN32
		server_hint.sin_addr.S_un.S_addr = ADDR_ANY;
#else
		server_hint.sin_addr.s_addr = INADDR_ANY;
#endif
		server_hint.sin_family = AF_INET;
		server_hint.sin_port = htons(54000);

#ifdef _WIN32
		if (bind(in, (sockaddr*)&server_hint, sizeof(server_hint)) == SOCKET_ERROR)
#else
		if (bind(in, (sockaddr*)&server_hint, sizeof(server_hint)) == SO_ERROR)
#endif
		{
#ifdef _WIN32
			Log::Send(1, "Can't bind socket! " + WSAGetLastError());
#endif
			return 1;
		}

		sockaddr_in client;
#ifdef _WIN32
		int client_length = sizeof(client);
#else
		unsigned int client_length = sizeof(client);
#endif
		char buf[1024];
		std::string text_1 = "";
		std::array<std::string, 3> input = { "" };
		int send_ok = 0;

		while (true)
		{
			memset(&client, 0, client_length);
			memset(buf, 0, 1024);
			int bytes_in = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &client_length);

			if (bytes_in == -1)
			{
				std::cout << "FATAL ERROR: -1" << std::endl;
			}

			char client_ip[256];
			memset(client_ip, 0, 256);
			inet_ntop(AF_INET, &client.sin_addr, client_ip, 256);
			std::string string_client_ip = client_ip;
			std::string string_buf = buf;
			Log::Send(0, "Message recv from: " + string_client_ip + ", " + string_buf);

			if (buf[0] != '/')
			{
				continue;
			}

			int i = 0;
			int j = 0;
			int counter = 0;

			while (buf[++i] != 0)
			{
				counter++;
			}

			buf[counter + 1] = ' ';
			i = 0;

			while (buf[++i] != '\0')
			{
				if (buf[i] != ' ' && buf[i] != ';')
				{
					text_1 += buf[i];
				}
				else
				{
					input[j] = text_1;
					text_1 = "";

					if (j != 2)
					{
						j++;
					}
				}
			}

			switch (GetPacket(input[0]))
			{
			case PACKET_TYPES::AUTH_LOGIN:
				if (input[1] != "" && input[2] != "")
				{
					int a_status = Auth::Login(input[1], input[2]);

					if (!a_status)
					{
						send_ok = sendto(in, "auth_succes", 12 + 1, 0, (sockaddr*)&client, sizeof(client));

#ifdef _WIN32
						if (bytes_in == SOCKET_ERROR)
#else
						if (bytes_in == SO_ERROR)
#endif
						{
#ifdef _WIN32
							std::cout << "That didn't work! " << WSAGetLastError() << '\n';
#endif
						}
					}
					else
					{
						send_ok = sendto(in, "auth_failure", 13 + 1, 0, (sockaddr*)&client, sizeof(client));

#ifdef _WIN32
						if (bytes_in == SOCKET_ERROR)
#else
						if (bytes_in == SO_ERROR)
#endif
						{
#ifdef _WIN32
							std::cout << "That didn't work! " << WSAGetLastError() << '\n';
#endif
						}
					}
				}
				else
				{
					send_ok = sendto(in, "wrong_args", 10 + 1, 0, (sockaddr*)&client, sizeof(client));
				}

				input[0] = "";
				input[1] = "";
				input[2] = "";
				break;

			case PACKET_TYPES::WRONG_PACKET:
				std::cout << input[0] << '\n';
				send_ok = sendto(in, "wrong_command", 256, 0, (sockaddr*)&client, sizeof(client));

#ifdef _WIN32
				if (bytes_in == SOCKET_ERROR)
#else
				if (bytes_in == SO_ERROR)
#endif
				{
#ifdef _WIN32
					std::cout << "That didn't work! " << WSAGetLastError() << '\n';
#endif
				}

				input[0] = "";
				input[1] = "";
				input[2] = "";
				break;
			}
		}

		return 0;
	}
}
