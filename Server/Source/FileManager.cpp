#include <map>
#include <vector>
#include <fstream>

#include "FileManager.h"

namespace FileManager
{
	bool Parse(const std::string& rFile)
	{
		if (std::ifstream file(rFile); !file.is_open())
			return false;
		else
		{
			std::string line;
			unsigned long long pos = line.find('=');
			std::string name = line.substr(0, pos);
			std::map<std::string, std::string> map;

			while (getline(file, line))
			{
				if (line[0] == '#' || line.empty())
					continue;

				pos = line.find(" = ");
				name = line.substr(0, pos);
				const std::string value = line.substr(pos + 3);
				map[name] = value;
			}

			vm[0] = map;
			file.close();
		}

		return true;
	}

	bool Write(const std::string& wFile, const std::string& text)
	{
		if (std::ofstream save(wFile, std::ios::app); !save.is_open())
			return false;
		else
		{
			save << text;
			save << "\n";
			save.close();
		}

		return true;
	}

	std::string ReadLine(std::string line, const unsigned int dValue)
	{
		line = vm[dValue][line];
		return line;
	}
}

namespace FileManager2
{
	bool Parse2(const std::string& rFile, const std::string& hostname)
	{
		if (std::ifstream file(rFile); !file.is_open())
			return false;
		else
		{
			std::string line;
			unsigned long long pos_hostname = line.find('[' + hostname + ']');
			unsigned long long pos_hostname_temp = line.find('[' + hostname + ']');
			unsigned long long pos_separator = line.find('=');
			std::string name = line.substr(0, pos_separator);
			std::string name_hostname;
			std::map<std::string, std::string> map;

			while (getline(file, line))
				if (line.find('[' + hostname + ']') != std::string::npos)
					break;

			if (line.find('[' + hostname + ']') != std::string::npos)
			{
				getline(file, line);

				while (line.find('[') == std::string::npos && !line.empty())
				{
					pos_separator = line.find(" = ");
					name = line.substr(0, pos_separator);
					const std::string value = line.substr(pos_separator + 3);
					map[name] = value;
					getline(file, line);
				}
			}

			vm2[0] = map;
			file.close();
		}

		return true;
	}

	bool GetHostNames(const std::string& rFile)
	{
		if (std::ifstream file(rFile); !file.is_open())
			return false;
		else
		{
			std::string line;
			std::string name_hostname;

			while (getline(file, line) && !file.eof())
				if (const unsigned long long pos_hostname = line.find('['); pos_hostname != std::string::npos)
				{
					if (const unsigned long long pos_hostname_temp = line.find(']'); pos_hostname_temp != std::string::npos)
						for (size_t i = pos_hostname + 1; i < pos_hostname_temp; i++)
							name_hostname += line[i];

					vm_string.emplace_back(name_hostname);
					name_hostname = "";
				}

			file.close();
		}

		return true;
	}
}
