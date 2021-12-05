/*
 * Author: Thorek
 */

#include "Char.h"
#include "Network.h"
// #include "MiniDump.h"
// #include "InputKeyboard.h"

int main()
{
	// SetUnhandledExceptionFilter(EterExceptionFilter);
	// return *(int*)0;

	Network::StartWinsock();
	Network::OpenConnection();
	// InputKeyboard();
	Character::Move();
}
