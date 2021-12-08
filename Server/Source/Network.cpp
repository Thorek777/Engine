#ifdef _WIN32
	#include <WinSock2.h>
	#include "WS2tcpip.h"
	#pragma comment(lib, "ws2_32.lib")
#else
	#include <cstring>
	#include "../../netdb.h"
	#include "../../unistd.h"
	#include "../../arpa/inet.h"
	#include "../../include/x86_64-linux-gnu/sys/socket.h"
#endif

#include "MySQL.h"
#include "Packet.h"
#include "Network.h"

int in;

namespace Network
{
#ifdef _WIN32
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
#endif

	int OpenConnection()
	{
#ifdef _WIN32
		StartWinsock();
#endif

#ifdef _WIN32
		in = socket(AF_INET, SOCK_DGRAM, 0);
#else
		in = socket(AF_INET, SOCK_DGRAM, 0);
#endif

		sockaddr_in server_hint{};

#ifdef _WIN32
		server_hint.sin_addr.S_un.S_addr = ADDR_ANY;
#else
		server_hint.sin_addr.s_addr = INADDR_ANY;
#endif

		server_hint.sin_family = AF_INET;
		server_hint.sin_port = htons(54000);

		if (bind(in, reinterpret_cast<sockaddr*>(&server_hint), sizeof server_hint) == -1)
		{
#ifdef _WIN32
			std::cout << "Can't bind socket! (" << WSAGetLastError() << ").";
#endif
			return 1;
		}

		ParseText();
		return 0;
	}

	int ParseText()
	{
		sockaddr_in client{};

#ifdef _WIN32
		int client_length = sizeof client;
#else
		unsigned int client_length = sizeof(client);
#endif

		std::string text_1;

		while (true)
		{
			char buf[1024];
			memset(&client, 0, client_length);
			memset(buf, 0, 1024);
			bytes_in = recvfrom(in, buf, 1024, 0, reinterpret_cast<sockaddr*>(&client), &client_length);

			if (bytes_in == -1)
				std::cout << "Fatal error! (-1)." << '\n';

			char client_ip[256] = {};
			inet_ntop(AF_INET, &client.sin_addr, client_ip, 256);
			std::string string_client_ip = client_ip;
			std::string string_buf = buf;
			std::cout << "Message recv from: " << client_ip << ", " << string_buf << '\n';

			if (buf[0] != '/')
				continue;

			int i = 0;
			int j = 0;
			int counter = 0;

			while (buf[++i] != 0)
				counter++;

			buf[counter + 1] = ' ';
			i = 0;

			while (buf[++i] != '\0')
			{
				if (buf[i] != ' ' && buf[i] != ';')
					text_1 += buf[i];
				else
				{
					input[j] = text_1;
					text_1 = "";

					if (j != 2)
						j++;
				}
			}

			ParsePacket();
			return 0;
		}
	}
}
