#include "RoundsCount.h"

int roundsCount = 0;
int ROUNDS_COUNT(int& difficulty)
{
	char key = -1;
	bool active1 = false,
		active2 = false,
		active3 = false,
		active4 = false;

	const int UP = 72,
		DOWN = 80,
		LEFT = 75,
		RIGHT = 77,
		ENTER = 13,
		ESC = 27;

	while (true)
	{
		FRAME();
		int RoundsCountX = 52, RoundsCountY = 10;

		GoToXY(RoundsCountX, RoundsCountY);
		PURPLE();
		cout << "Number of rounds";

		GoToXY(RoundsCountX + 7, RoundsCountY + 2);
		if (active1) WHITE();
		else GRAY();
		cout << '^';

		GoToXY(RoundsCountX + 4, RoundsCountY + 3);
		if (active2) WHITE();
		else GRAY();
		cout << '<';

		if (roundsCount >= 0 and roundsCount <= 99)
			GoToXY(RoundsCountX + 7, RoundsCountY + 3);
		else if (roundsCount >= 100 and roundsCount <= 9999)
			GoToXY(RoundsCountX + 6, RoundsCountY + 3);
		else if (roundsCount >= 10000 and roundsCount <= 99999)
			GoToXY(RoundsCountX + 5, RoundsCountY + 3);
		GREEN();
		cout << roundsCount;

		GoToXY(RoundsCountX + 10, RoundsCountY + 3);
		if (active3) WHITE();
		else GRAY();
		cout << '>';

		GoToXY(RoundsCountX + 7, RoundsCountY + 4);
		if (active4) WHITE();
		else GRAY();
		cout << 'v';

		if (active1 or active2 or active3 or active4)
		{
			Sleep(100);
			return ROUNDS_COUNT(difficulty);
		}

		Input(key);

		if (key == -32)
			Input(key);
		Clear();

		switch (key)
		{
		case UP:
			active1 = true;
			active2 = false;
			active3 = false;
			active4 = false;
			if (roundsCount <= 99999)
				roundsCount += 10;
			break;
		case DOWN:
			active1 = false;
			active2 = false;
			active3 = false;
			active4 = true;
			if (roundsCount >= 10)
				roundsCount -= 10;
			break;
		case LEFT:
			active1 = false;
			active2 = true;
			active3 = false;
			active4 = false;
			if (roundsCount != 0)
				roundsCount--;
			break;

		case RIGHT:
			active1 = false;
			active2 = false;
			active3 = true;
			active4 = false;
			roundsCount++;
			break;

		case ENTER:
			if (roundsCount == 0)
			{
				Error();
				continue;
			}
			return GameProcess(difficulty, roundsCount);

		case ESC:
			return DIFFICULTY();
		default:
			Error();
			break;
		}
	}

	return 0;
}
