#include "GameProcess.h"


int GameProcess(int& difficulty, int& roundsCount)
{
	switch (difficulty)
	{
	case 1:
		return Play_vs_E(roundsCount);
    case 2:
        return Play_vs_M(roundsCount);
    case 3:
        return Play_vs_H(roundsCount);
    case -1:
        return ROUNDS_COUNT(difficulty);
	}
}

int Play_vs_E(int& roundsCount)
{
	plr::Player player;
	bot::EasyBot eBot;

	int realCount = 1;
	char playersChoice, botsChoice;
    const char ESC = 27;

    while (realCount <= roundsCount)
	{
		playersChoice = player.do_choise(player, eBot, realCount, roundsCount);
		botsChoice = eBot.do_choice(playersChoice);

        int exit = -1;
        if (playersChoice == ESC)
            return GameProcess(exit, roundsCount);

        char result = Check_PvE(player, eBot, playersChoice, botsChoice);

        GameZoneFRAME();

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
        GoToXY(61, 27);
        PURPLE();
        cout << "Score: ";
        WHITE();
        cout << eBot.getEasyBotScore();

        switch (result)
        {
        case 'w':
            GREEN();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            RED();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'd':
            WHITE();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'l':
            RED();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            GREEN();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;
        }

        Sleep(1500);
        Clear();
		realCount++;
	}

    int playerScore = player.getPlayerScore();
    int botScore = eBot.getEasyBotScore();
    
    char key = -1;
    vector<string>text = { "Restart", "Menu" };
    int active = 0;
    while(true)
    {
        if (playerScore > botScore)
        {
            FRAME();
            GoToXY(55, 10);
            GREEN();
            cout << "YOU WIN !";
        }
        else if (playerScore < botScore)
        {
            FRAME();
            GoToXY(55, 10);
            RED();
            cout << "YOU LOSE !";
        }
        else if (playerScore == botScore)
        {
            FRAME();
            GoToXY(55, 10);
            PURPLE();
            cout << "DRAW";
        }

        int y = 12;
        for (int i = 0; i < text.size(); i++)
        {
            if (i == active)
                WHITE();
            else GRAY();
            GoToXY(55, y++);
            cout << text[i];
        }
        
        Input(key);

        if (key == -32)
            Input(key);
        Clear();

        const int UP = 72,
            DOWN = 80,
            ENTER = 13;
        switch (key)
        {
        case UP:
            if (active == 1)
                active--;
            break;
        case DOWN:
            if (active == 0)
                active++;
            break;
        case ENTER:
            switch (active)
            {
            case 0:
                return Play_vs_E(roundsCount);
            case 1:
                return MENU(1);
            }
            break;
        }
    }
    return 0;
}
char Check_PvE(plr::Player& player, bot::EasyBot& eBot, char& playersChoice, char& ebotsChoice)
{
    switch (playersChoice)
    {
    case 's':
        switch (ebotsChoice)
        {
        case 'p':
            player.plusPlayerScore();
            return 'w';
        case 's':
            return 'd';
        case 'r':
            eBot.plusEasyBotScore();
            return 'l';
        }
        break;
    case 'r':
        switch (ebotsChoice)
        {
        case 's':
            player.plusPlayerScore();
            return 'w';
        case 'r':
            return 'd';
        case 'p':
            eBot.plusEasyBotScore();
            return 'l';
        }
        break;
    case 'p':
        switch (ebotsChoice)
        {
        case 'r':
            player.plusPlayerScore();
            return 'w';
        case 'p':
            return 'd';
        case 's':
            eBot.plusEasyBotScore();
            return 'l';
        }
        break;
    }
}


int Play_vs_M(int& roundsCount)
{
    plr::Player player;
    bot::MediumBot mBot;

    int realCount = 1;
    char playersChoice, botsChoice;
    const char ESC = 27;

    while (realCount <= roundsCount)
    {
        playersChoice = player.do_choise(player, mBot, realCount, roundsCount);
        botsChoice = mBot.do_choice(playersChoice);

        int exit = -1;
        if (playersChoice == ESC)
            return GameProcess(exit, roundsCount);

        char result = Check_PvM(player, mBot, playersChoice, botsChoice);

        GameZoneFRAME();

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
        GoToXY(61, 27);
        PURPLE();
        cout << "Score: ";
        WHITE();
        cout << mBot.getMediumBotScore();

        switch (result)
        {
        case 'w':
            GREEN();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            RED();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'd':
            WHITE();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'l':
            RED();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            GREEN();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;
        }

        Sleep(1500);
        Clear();
        realCount++;
    }

    int playerScore = player.getPlayerScore();
    int botScore = mBot.getMediumBotScore();

    char key = -1;
    vector<string>text = { "Restart", "Menu" };
    int active = 0;
    while (true)
    {
        if (playerScore > botScore)
        {
            FRAME();
            GoToXY(55, 10);
            GREEN();
            cout << "YOU WIN !";
        }
        else if (playerScore < botScore)
        {
            FRAME();
            GoToXY(55, 10);
            RED();
            cout << "YOU LOSE !";
        }
        else if (playerScore == botScore)
        {
            FRAME();
            GoToXY(55, 10);
            PURPLE();
            cout << "DRAW";
        }

        int y = 12;
        for (int i = 0; i < text.size(); i++)
        {
            if (i == active)
                WHITE();
            else GRAY();
            GoToXY(55, y++);
            cout << text[i];
        }

        Input(key);

        if (key == -32)
            Input(key);
        Clear();

        const int UP = 72,
            DOWN = 80,
            ENTER = 13;
        switch (key)
        {
        case UP:
            if (active == 1)
                active--;
            break;
        case DOWN:
            if (active == 0)
                active++;
            break;
        case ENTER:
            switch (active)
            {
            case 0:
                return Play_vs_M(roundsCount);
            case 1:
                return MENU(1);
            }
            break;
        }
    }
    return 0;
}
char Check_PvM(plr::Player& player, bot::MediumBot& mBot, char& playersChoice, char& mBotsChoice)
{
    switch (playersChoice)
    {
    case 's':
        switch (mBotsChoice)
        {
        case 'p':
            player.plusPlayerScore();
            return 'w';
        case 's':
            return 'd';
        case 'r':
            mBot.plusMediumBotScore();
            return 'l';
        }
        break;
    case 'r':
        switch (mBotsChoice)
        {
        case 's':
            player.plusPlayerScore();
            return 'w';
        case 'r':
            return 'd';
        case 'p':
            mBot.plusMediumBotScore();
            return 'l';
        }
        break;
    case 'p':
        switch (mBotsChoice)
        {
        case 'r':
            player.plusPlayerScore();
            return 'w';
        case 'p':
            return 'd';
        case 's':
            mBot.plusMediumBotScore();
            return 'l';
        }
        break;
    }
}

int Play_vs_H(int& roundsCount)
{
    plr::Player player;
    bot::HardBot hBot;

    int realCount = 1;
    char playersChoice, botsChoice;
    const char ESC = 27;

    while (realCount <= roundsCount)
    {
        playersChoice = player.do_choise(player, hBot, realCount, roundsCount);
        botsChoice = hBot.do_choice(playersChoice);

        int exit = -1;
        if (playersChoice == ESC)
            return GameProcess(exit, roundsCount);

        char result = Check_PvH(player, hBot, playersChoice, botsChoice);

        GameZoneFRAME();

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
        GoToXY(61, 27);
        PURPLE();
        cout << "Score: ";
        WHITE();
        cout << hBot.getHardBotScore();

        switch (result)
        {
        case 'w':
            GREEN();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            RED();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'd':
            WHITE();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;

        case 'l':
            RED();
            switch (playersChoice)
            {
            case 's':
                ScissorsOutPlayer();
                break;
            case 'r':
                RockOutPlayer();
                break;
            case 'p':
                PaperOutPlayer();
                break;
            }
            GREEN();
            switch (botsChoice)
            {
            case 's':
                ScissorsOutBot();
                break;
            case 'r':
                RockOutBot();
                break;
            case 'p':
                PaperOutBot();
                break;
            }
            break;
        }

        Sleep(1500);
        Clear();
        realCount++;
    }

    int playerScore = player.getPlayerScore();
    int botScore = hBot.getHardBotScore();

    char key = -1;
    vector<string>text = { "Restart", "Menu" };
    int active = 0;
    while (true)
    {
        if (playerScore > botScore)
        {
            FRAME();
            GoToXY(55, 10);
            GREEN();
            cout << "YOU WIN !";
        }
        else if (playerScore < botScore)
        {
            FRAME();
            GoToXY(55, 10);
            RED();
            cout << "YOU LOSE !";
        }
        else if (playerScore == botScore)
        {
            FRAME();
            GoToXY(55, 10);
            PURPLE();
            cout << "DRAW";
        }

        int y = 12;
        for (int i = 0; i < text.size(); i++)
        {
            if (i == active)
                WHITE();
            else GRAY();
            GoToXY(55, y++);
            cout << text[i];
        }

        Input(key);

        if (key == -32)
            Input(key);
        Clear();

        const int UP = 72,
            DOWN = 80,
            ENTER = 13;
        switch (key)
        {
        case UP:
            if (active == 1)
                active--;
            break;
        case DOWN:
            if (active == 0)
                active++;
            break;
        case ENTER:
            switch (active)
            {
            case 0:
                return Play_vs_H(roundsCount);
            case 1:
                return MENU(1);
            }
            break;
        }
    }
    return 0;
}

char Check_PvH(plr::Player& player, bot::HardBot& hBot, char& playersChoice, char& hBotsChoice)
{
    switch (playersChoice)
    {
    case 's':
        switch (hBotsChoice)
        {
        case 'p':
            player.plusPlayerScore();
            return 'w';
        case 's':
            return 'd';
        case 'r':
            hBot.plusHardBotScore();
            return 'l';
        }
        break;
    case 'r':
        switch (hBotsChoice)
        {
        case 's':
            player.plusPlayerScore();
            return 'w';
        case 'r':
            return 'd';
        case 'p':
            hBot.plusHardBotScore();
            return 'l';
        }
        break;
    case 'p':
        switch (hBotsChoice)
        {
        case 'r':
            player.plusPlayerScore();
            return 'w';
        case 'p':
            return 'd';
        case 's':
            hBot.plusHardBotScore();
            return 'l';
        }
        break;
    }
}


