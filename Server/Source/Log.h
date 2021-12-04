/*
 * Author: Thorek
 */

#pragma once

#include <iostream>

namespace Log
{
	auto Delete() -> bool;
	void Send(int type, const std::string& log);
}
