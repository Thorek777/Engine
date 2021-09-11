#include "Log.hpp"
#include "MySQL.hpp"
#include "Network.hpp"

#define Start main

int Start()
{
	Log::Delete();

#ifdef _WIN32
	MySQL::Connect("127.0.0.1", "root", "", "account", 3307);
#else
	MySQL::Connect("192.168.0.111", "thorek", "thorek123456", "account", 3306);
#endif

	Network::OpenConnection();
}
