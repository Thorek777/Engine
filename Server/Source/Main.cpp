#include "Log.h"
#include "MySQL.h"
#include "Config.h"
#include "Network.h"

int main()
{
	Log::Delete();

	if (Config::Init() == false)
	{
#ifdef _WIN32
		std::cout << "Cannot open ../Database/Config.ini file!" << '\n';
#endif

		Log::Send(1, "Cannot open ../Database/Config.ini file!");
		return false;
	}

#ifdef _WIN32 // For XAMPP.
	MySQL::Connect(optValue["IP"], optValue["LOGIN"], optValue["PASSWORD"], optValue["DATABASE"], stoi(optValue["PORT"]));
#else         // For MySQL installed on Linux.
	MySQL::Connect("192.168.0.111", "thorek", "thorek123456", "account", 3306);
#endif

	Network::OpenConnection();
}
