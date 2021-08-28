#include "Log.hpp"
#include "Auth.hpp"
#include "MySQL.hpp"
#include "Network.hpp"

#define Start main

int Start()
{
	Log::Delete();
	MySQL::Connect("127.0.0.1", "root", "", "account", 3307);
	Network::Test();
	Auth::Login("Thorek", "1234");
}
