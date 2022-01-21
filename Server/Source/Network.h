#pragma once

#include <array>

inline int bytes_in;
inline std::array<std::string, 3> input = { "" };

namespace Network
{
	int OpenConnection();
	int ParseText();
}
