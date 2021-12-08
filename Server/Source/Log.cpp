#include <chrono>
#include <fstream>
#include <iostream>

#pragma warning(disable: 4996)

namespace Log
{
	bool Delete()
	{
		return remove("Syslog.txt") == 0 || 0 == remove("Syserr.txt");
	}

	void Send(const int type, const std::string& log)
	{
		const time_t now = time(nullptr);
		const tm* gmtm = gmtime(&now);
		const char* dt = asctime(gmtm);

		if (type == 0)
		{
			std::ofstream file("Syslog.txt", std::ios_base::app);
			std::cout << log << '\n';
			file << dt << log << '\n' << '\n';
			file.close();
		}
		else
		{
			std::ofstream file("Syserr.txt", std::ios_base::app);
			std::cout << log << '\n';
			file << dt << log << '\n' << '\n';
			file.close();
		}
	}
}
