#include "Network.h"
#include "InputKeyboard.h"

int main()
{
	Network::StartWinsock();
	Network::OpenConnection();
	InputKeyboard();
}
