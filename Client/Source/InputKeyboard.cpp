#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "PlayerChat.h"

// int chatIsOpen;

int InputKeyboard()
{
	while (true)
	{
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			// if (chatIsOpen == 0)
				Player::Chat::Open();

			// chatIsOpen = 1;
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
