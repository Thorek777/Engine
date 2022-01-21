#pragma once

#include <iostream>

namespace Log
{
	bool Delete();
	void Send(int type, const std::string& log);
}
