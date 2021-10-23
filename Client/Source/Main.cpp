#include "Network.h"
#include "InputKeyboard.h"
// #include "MiniDump.h"

int main()
{
	// SetUnhandledExceptionFilter(EterExceptionFilter);
	// return *(int*)0;

	Network::StartWinsock();
	Network::OpenConnection();
	InputKeyboard();
}
