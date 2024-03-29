#include "Player.h"
#include "RoundsCount.h"

plr::Player::Player()
{
	this->playerScore = 0;
}

int plr::Player::getPlayerScore()
{
	return this->playerScore;
}

void plr::Player::plusPlayerScore()
{
	++(this->playerScore);
}

int i = 0;
char plr::Player::do_choise(plr::Player& player, bot::EasyBot& eBot, int& realCount, int& roundsCount)
{
	const char attributs[]{ 'r','s','p' };
	const char Left[]{ "<=" };
	const char Right[]{ "=>" };

	char key = -1;

	bool active_L = false,
		 active_R = false;

	const int LEFT = 75,
			  RIGHT = 77,
			  ENTER = 13,
			  ESC = 27;

	while (true)
	{
		GameZoneFRAME();

		YELLOW();
		switch (i)
		{
		case 0:
			RockOutPlayer();
			break;
		case 1:
			ScissorsOutPlayer();
			break;
		case 2:
			PaperOutPlayer();
			break;
		}

		GoToXY(20, 16);
		if (active_L)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Left[i];

		GoToXY(42, 16);
		if (active_R)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Right[i];

		WHITE();
        GoToXY(1, 1);
        cout << "PLAYER";
        GoToXY(116, 1);
        cout << "BOT";

		GoToXY(55, 2);
		PURPLE();
		cout << "Round: ";
		WHITE();
		cout << realCount;
		GRAY();
		cout << " / " << roundsCount;

		GoToXY(1, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << player.getPlayerScore();

		YELLOW();
		UnkownOutBot();
		GoToXY(61, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << eBot.getEasyBotScore();

		if (active_L or active_R)
		{
			Sleep(100);
			return player.do_choise(player,eBot,realCount,roundsCount);
		}

		key = _getch();

		if (key == -32)
			key = _getch();
		Clear();

		switch (key)
		{
		case LEFT:
			active_L = true;
			active_R = false;
			if (i == 0)
				i += 2;
			else --i;
			break;

		case RIGHT:
			active_L = false;
			active_R = true;
			if (i == 2)
				i -= 2;
			else ++i;
			break;

		case ENTER:
			switch (i)
			{
			case 0:
				return 'r';
			case 1:
				return 's';
			case 2:
				return 'p';
			}
			break;
		case ESC:
			return ESC;
		}
	}
}

char plr::Player::do_choise(plr::Player& player, bot::MediumBot mBot, int& realCount, int& roundsCount)
{
	const char attributs[]{ 'r','s','p' };
	const char Left[]{ "<=" };
	const char Right[]{ "=>" };

	char key = -1;

	bool active_L = false,
		active_R = false;

	const int LEFT = 75,
		RIGHT = 77,
		ENTER = 13,
		ESC = 27;

	while (true)
	{
		GameZoneFRAME();

		YELLOW();
		switch (i)
		{
		case 0:
			RockOutPlayer();
			break;
		case 1:
			ScissorsOutPlayer();
			break;
		case 2:
			PaperOutPlayer();
			break;
		}

		GoToXY(20, 16);
		if (active_L)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Left[i];

		GoToXY(42, 16);
		if (active_R)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Right[i];

		WHITE();
		GoToXY(1, 1);
		cout << "PLAYER";
		GoToXY(116, 1);
		cout << "BOT";

		GoToXY(55, 2);
		PURPLE();
		cout << "Round: ";
		WHITE();
		cout << realCount;
		GRAY();
		cout << " / " << roundsCount;

		GoToXY(1, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << player.getPlayerScore();

		YELLOW();
		UnkownOutBot();
		GoToXY(61, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << mBot.getMediumBotScore();

		if (active_L or active_R)
		{
			Sleep(100);
			return player.do_choise(player, mBot, realCount, roundsCount);
		}

		Input(key);

		if (key == -32)
			key = _getch();
		Clear();

		switch (key)
		{
		case LEFT:
			active_L = true;
			active_R = false;
			if (i == 0)
				i += 2;
			else --i;
			break;

		case RIGHT:
			active_L = false;
			active_R = true;
			if (i == 2)
				i -= 2;
			else ++i;
			break;

		case ENTER:
			switch (i)
			{
			case 0:
				return 'r';
			case 1:
				return 's';
			case 2:
				return 'p';
			}
			break;
		case ESC:
			return ESC;
		}
	}
}

char plr::Player::do_choise(plr::Player& player, bot::HardBot hBot, int& realCount, int& roundsCount)
{
	const char attributs[]{ 'r','s','p' };
	const char Left[]{ "<=" };
	const char Right[]{ "=>" };

	char key = -1;

	bool active_L = false,
		active_R = false;

	const int LEFT = 75,
		RIGHT = 77,
		ENTER = 13,
		ESC = 27;

	while (true)
	{
		GameZoneFRAME();

		YELLOW();
		switch (i)
		{
		case 0:
			RockOutPlayer();
			break;
		case 1:
			ScissorsOutPlayer();
			break;
		case 2:
			PaperOutPlayer();
			break;
		}

		GoToXY(20, 16);
		if (active_L)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Left[i];

		GoToXY(42, 16);
		if (active_R)WHITE();
		else GRAY();
		for (int i = 0; i < 2; i++)
			cout << Right[i];

		WHITE();
		GoToXY(1, 1);
		cout << "PLAYER";
		GoToXY(116, 1);
		cout << "BOT";

		GoToXY(55, 2);
		PURPLE();
		cout << "Round: ";
		WHITE();
		cout << realCount;
		GRAY();
		cout << " / " << roundsCount;

		GoToXY(1, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << player.getPlayerScore();

		YELLOW();
		UnkownOutBot();
		GoToXY(61, 27);
		PURPLE();
		cout << "Score: ";
		WHITE();
		cout << hBot.getHardBotScore();

		if (active_L or active_R)
		{
			Sleep(100);
			return player.do_choise(player, hBot, realCount, roundsCount);
		}

		Input(key);

		if (key == -32)
			key = _getch();
		Clear();

		switch (key)
		{
		case LEFT:
			active_L = true;
			active_R = false;
			if (i == 0)
				i += 2;
			else --i;
			break;

		case RIGHT:
			active_L = false;
			active_R = true;
			if (i == 2)
				i -= 2;
			else ++i;
			break;

		case ENTER:
			switch (i)
			{
			case 0:
				return 'r';
			case 1:
				return 's';
			case 2:
				return 'p';
			}
			break;
		case ESC:
			return ESC;
		}
	}
}






