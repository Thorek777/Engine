#ifndef AUTH_HPP
#define AUTH_HPP

#include <string>

inline bool auth_status = false;

namespace Auth
{
	int Login(const std::string& login, const std::string& password);
}
#endif
