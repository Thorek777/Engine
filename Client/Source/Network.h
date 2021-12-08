#pragma once

#include <iostream>
#include <WS2tcpip.h>

extern sockaddr_in server2;
extern unsigned long long out2;

namespace Network
{
	int StartWinsock();
	int OpenConnection();
	int SendPacket(std::string packet);
}
