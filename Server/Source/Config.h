#pragma once

#include <map>
#include <string>
#include <vector>

inline std::vector<std::string> optText = { "IP", "PORT", "LOGIN", "PASSWORD", "DATABASE" };
inline std::map<std::string, std::string> optValue;

namespace Config
{
	bool Initialize();
}
