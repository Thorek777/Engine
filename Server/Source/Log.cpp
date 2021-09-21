#include <chrono>
#include <fstream>

#include "Log.hpp"

namespace Log
{
	bool Delete()
	{
		return remove("Syslog.txt") == 0 || 0 == remove("Syserr.txt") ? true : false;
	}

	std::ofstream operator<<(const std::ofstream&,
	                         const std::chrono::local_time<std::common_type_t<
		                         std::chrono::duration<long long, std::ratio<1, 10000000>>, std::chrono::duration<long
			                         long>>>&)
	{
		return {};
	}

	void Send(const int type, const std::string& log)
	{
		const auto now = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());

		if (type == 0)
		{
			std::ofstream file("Syslog.txt", std::ios_base::app);
			file << now << ":	" << log << '\n' << '\n';
			file.close();

#ifdef _DEBUG
			std::cout << "Log generated!" << '\n';
#endif
		}
		else
		{
			std::ofstream file("Syserr.txt", std::ios_base::app);
			file << now << ":	" << log << '\n' << '\n';
			file.close();

#ifdef _DEBUG
			std::cout << "Error generated!" << '\n';
#endif
		}
	}
}
