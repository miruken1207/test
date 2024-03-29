#include "Difficulty.h"

int DIFFICULTY()
{
	vector<string>difficulty =
	{
		"Easy",
		"Medium",
		"Hard",
	};

	char key = -1;
	int active = 0;
	const int UP = 72,
		DOWN = 80,
		ENTER = 13,
		ESC = 27;

	int easy = 1;
	int medium = 2;
	int hard = 3;

	while (true)
	{
		FRAME();

		int difficultyX = 55, difficultyY = 11;

		for (int i = 0; i < difficulty.size(); i++)
		{
			if (i == active)
				WHITE();
			else
				GRAY();

			GoToXY(difficultyX, difficultyY++);
			cout << difficulty[i];
		}

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
			if (active < 2)
			{
				active++;
			}
			break;
		case ENTER:
			switch (active)
			{
			case 0:
				return ROUNDS_COUNT(easy);
			case 1:
				return ROUNDS_COUNT(medium);
			case 2:
				return ROUNDS_COUNT(hard);
			}
			break;
		case ESC:
			return MENU(1);
			break;
		default:
			Error();
			break;
		}
	}

    return 0;
}
