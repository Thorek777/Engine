/*
 * Author: Thorek
 */

#pragma once

#include <string>
#include <iostream>

#include "Auth.h"
#include "Network.h"

enum class PacketTypes
{
	UNKNOWN_PACKET,
	HEADER_CS_AUTH,
};

inline PacketTypes GetPacket(const std::string& command)
{
	if (command == "login")
	{
		return PacketTypes::HEADER_CS_AUTH;
	}

	return PacketTypes::UNKNOWN_PACKET;
}

inline void ParsePacket()
{
	switch (GetPacket(input[0]))
	{
	case PacketTypes::HEADER_CS_AUTH:
		if (!input[1].empty() && !input[2].empty())
		{
			if (const int status = Auth::Login(input[1], input[2]); status)
			{
				if (bytes_in == -1)
				{
#ifdef _WIN32
					std::cout << "That didn't work! (" << WSAGetLastError() << ")." << '\n';
#else
					return;
#endif
				}
			}
		}

		input[0] = "";
		input[1] = "";
		input[2] = "";
		break;

	case PacketTypes::UNKNOWN_PACKET:
		std::cout << "Unknown command!" << '\n';

		if (bytes_in == -1)
		{
#ifdef _WIN32
			std::cout << "That didn't work! (" << WSAGetLastError() << ")." << '\n';
#else
			return;
#endif
		}

		input[0] = "";
		input[1] = "";
		input[2] = "";
		break;
	}
}
