#pragma once

#include <string>
#include <vector>

inline std::map<std::string, std::string> emptyMap{ { "Empty", "Empty" } };
inline std::vector vm{ emptyMap };
inline std::vector vm2{ emptyMap };
inline std::vector<std::string> vm_string{};

namespace FileManager
{
	bool Parse(const std::string& rFile);
	bool Write(const std::string& wFile, const std::string& text);
	std::string ReadLine(std::string line, unsigned int dValue = 0);
}

namespace FileManager2
{
	bool Parse2(const std::string& rFile, const std::string& hostname);
	bool GetHostNames(const std::string& rFile);
}
