#include "Menu.h"

int MENU(int start)
{
	if (start == 0)
		ANIMATION();

	const vector<string>menu =
	{
	  "    Start",
	  "    Exit"
	};

	char key = -1;
	int active = 0;
	const int UP = 72,
		DOWN = 80,
		ENTER = 13,
		ESC = 27;

	while (true)
	{
		FRAME();
		int menuX = 55, menuY = 12;

		GoToXY(menuX, menuY - 2);
		YELLOW();
		cout << "DON DON ZIKI";

		for (int i = 0; i < menu.size(); i++)
		{
			if (i == active)
				WHITE();
			else
				GRAY();

			GoToXY(55, menuY++);
			cout << menu[i];
		}

		if(start==0)
			Sleep(1000);
		
		Input(key);

		if (key == -32)
			Input(key);
		Clear();

		switch (key)
		{
		case UP:
			if (active > 0)
			{
				active--;
			}
			break;
		case DOWN:
			if (active < 1)
			{
				active++;
			}
			break;
		case ENTER:
			switch (active)
			{
			case 0:
				return DIFFICULTY();
			case 1:
				return ANIMATION();
			}
			break;
		case ESC:
			return ANIMATION();
		default:
			Error();
			break;
		}
	}
}
