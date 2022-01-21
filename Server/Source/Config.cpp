#include "Config.h"
#include "FileManager.h"

namespace Config
{
	bool Initialize()
	{
		// Parse config file:
		if (!FileManager::Parse("SF/Database/Conf.ini"))
			return false;

		// If file has been parsed, insert data to map (optValue):
		for (const auto& i : optText)
			optValue.insert(std::pair(i, FileManager::ReadLine(i)));

		return true;
	}
}
