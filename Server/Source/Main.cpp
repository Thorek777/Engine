#include "Log.h"
#include "MySQL.h"
#include "Config.h"
#include "Network.h"

int main()
{
	// Delete all logs:
	Log::Delete();

	// Initialize config:
	if (Config::Initialize() == false)
	{
		Log::Send(1, "Cannot open ../Database/Config.ini file!");

#ifdef _WIN32
		std::cout << "Cannot open ../Database/Config.ini file!" << '\n';
#endif

		return 1;
	}

	// If config has been initialized, connect Server with MySQL using values from config:
#ifdef _WIN32 // For XAMPP.
	MySQL::Connect(optValue["IP"], optValue["LOGIN"], optValue["PASSWORD"], optValue["DATABASE"], stoi(optValue["PORT"]));
#else         // For MySQL installed on Linux.
	MySQL::Connect("192.168.0.111", "thorek", "thorek123456", "account", 3306);
#endif

	// And open Server connection:
	Network::OpenConnection();
}
