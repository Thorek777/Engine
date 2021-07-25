#include "../../../Common/Namespaces.hpp"
#include "../../../Common/D_Includes.hpp"
#include "../../../Common/O_Includes.hpp"

#pragma warning(disable: 4996)

void SendLog(int type, string log)
{
	time_t c_time;
	struct tm* ptr;
	time(&c_time);
	ptr = localtime(&c_time);
	char* data = asctime(ptr);

	if (type == 0) // Normal log.
	{
		ofstream file("N-Logs.txt", ios_base::app);
		file << data << log << "\n" << "\n";
		file.close();

		cout << "Log generated! Check N-Logs.txt file." << "\n";
	}
	else if (type == 1) // Error log.
	{
		ofstream file("E-Logs.txt", ios_base::app);
		file << data << log << "\n" << "\n";
		file.close();

		cout << "Log generated! Check E-Logs.txt file." << "\n";
	}
	else // Unknown log, fix.
	{
		return;
	}
}
