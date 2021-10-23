#include <conio.h>
#include <Windows.h>
#include "PlayerChat.h"

int InputKeyboard()
{
	while (true)
	{
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			Player::Chat::Open();
			break; // Without this, while (true) is active all the time.
		}
	}

	return 0;
}

void ClearKeyboardBuffer()
{
	while (_kbhit())
		(void)_getch(); // Muted C6031 warning.
}
