#pragma once

#include <string>

enum class PacketTypes
{
	UNKNOWN_PACKET,

	// Client -> Server packet(s):
	CS_AUTH_PACKET,
};

inline PacketTypes GetPacket(const std::string& command)
{
	if (command == "login")
		return PacketTypes::CS_AUTH_PACKET;

	return PacketTypes::UNKNOWN_PACKET;
}
