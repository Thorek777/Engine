#include <fstream>

#include "Log.hpp"

#pragma warning(disable: 4996)

namespace Log
{
	void Send(int type, std::string log)
	{
		time_t c_time;
		struct tm* ptr;
		time(&c_time);
		ptr = localtime(&c_time);
		char* data = asctime(ptr);

		if (type == 0)
		{
			std::ofstream file("Syslog.txt", std::ios_base::app);
			file << data << log << '\n' << '\n';
			file.close();

			std::cout << "Log generated! Check ""Syslog.txt"" file." << '\n';
		}
		else if (type == 1)
		{
			std::ofstream file("Syserr.txt", std::ios_base::app);
			file << data << log << '\n' << '\n';
			file.close();

			std::cout << "Error generated! Check ""Syserr.txt"" file." << '\n';
		}
	}

	bool Delete()
	{
		if (remove("Syslog.txt") == 0 || remove("Syserr.txt") == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
