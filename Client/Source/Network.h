/*
 * Author: Thorek
 */

#pragma once

#include <WS2tcpip.h>

extern sockaddr_in server2;
extern unsigned long long out2;

namespace Network
{
	int StartWinsock();
	int OpenConnection();
}
