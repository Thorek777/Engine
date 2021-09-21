#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

namespace Log
{
	bool Delete();
	void Send(int type, const std::string& log);
}
#endif
