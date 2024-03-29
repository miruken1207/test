#pragma once

#include "SystemCommands.h"
#include "Bot.h"

namespace plr
{
	class Player
	{
    private:
        int playerScore;
        const char choises[3]{ 's','r','p' };
    public:
        Player();
        int getPlayerScore();
        void plusPlayerScore();
        char do_choise(plr::Player& player, bot::EasyBot& eBot, int& realCount, int & roundsCount);
        char do_choise(plr::Player& player, bot::MediumBot mBot, int& realCount, int& roundsCount);
        char do_choise(plr::Player& player, bot::HardBot hBot, int& realCount, int& roundsCount);
	};
}

