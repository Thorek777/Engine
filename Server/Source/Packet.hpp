#pragma once

#include <string>

enum class PacketTypes
{
	WRONG_PACKET,
	AUTH_LOGIN,
};

inline PacketTypes GetPacket(const std::string& command)
{
	if (command == "login")
	{
		return PacketTypes::AUTH_LOGIN;
	}

	return PacketTypes::WRONG_PACKET;
}
