/*
 * Author: Thorek
 */

#pragma once

#include <string>

namespace Auth
{
	auto Login(const std::string& login, const std::string& password) -> int;
}
