#include "Config.h"
#include "FileManager.h"

namespace Config
{
	bool Init()
	{
		if (!FileManager::Parse("../Database/Conf.ini"))
			return false;

		for (const auto& i : optText)
			optValue.insert(std::pair(i, FileManager::ReadLine(i)));

		return true;
	}
}
