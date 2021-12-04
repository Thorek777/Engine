/*
 * Author: Thorek
 */

#include "Log.h"
#include "MySQL.h"
#include "Network.h"

int main()
{
	Log::Delete();

#ifdef _WIN32 // For XAMPP.
	MySQL::Connect("127.0.0.1", "root", "", "account", 3307);
#else         // For MySQL installed on Linux.
	MySQL::Connect("192.168.0.111", "thorek", "thorek123456", "account", 3306);
#endif

	Network::OpenConnection();
}
