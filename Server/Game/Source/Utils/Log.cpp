#include <iostream>
#include <fstream>

#pragma warning(disable: 4996)

void SendLog(int type, std::string log)
{
	time_t c_time;
	struct tm* ptr;
	time(&c_time);
	ptr = localtime(&c_time);
	char* data = asctime(ptr);

	if (type == 0) // Normal log.
	{
		std::ofstream file("N-Log.txt", std::ios_base::app);
		file << data << log << "\n" << "\n";
		file.close();

		std::cout << "Log generated! Check N-Log.txt file." << "\n";
	}
	else if (type == 1) // Error log.
	{
		std::ofstream file("E-Log.txt", std::ios_base::app);
		file << data << log << "\n" << "\n";
		file.close();

		std::cout << "Log generated! Check E-Log.txt file." << "\n";
	}
	else // Unknown log, fix.
	{
		return;
	}
}

bool DeleteLog()
{
	if (remove("N-Log.txt") == 0 || remove("E-Log.txt") == 0)
		return true;
	else
		return false;
}
