#include "../../Common/D_Includes.hpp"
#include "../../Common/O_Includes.hpp"

#define Start main

int Start()
{
	MySQL::SetDatabse("account");
	MySQL::Connect("localhost", "root", "", 3306);
	Login("Thorek", "1234");
	return 0;
}
