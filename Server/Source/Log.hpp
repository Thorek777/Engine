#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <iostream>

namespace Log
{
	bool Delete();
	void Send(int type, std::string log);
}
#endif
