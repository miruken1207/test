#pragma once

#include "SystemCommands.h"

namespace bot
{
    class EasyBot
    {
    private:
        int EasyBotScore;

        const char vs_Scissors[6]{ 'p', 'p', 'p', 's', 's', 'r' };
        const char vs_Rock[6]{ 's', 's', 's', 'r', 'r', 'p' };
        const char vs_Paper[6]{ 'r', 'r', 'r', 'p', 'p', 's' };

    public:
        const string botsNick = "PrOsTaChOk";
        EasyBot();
        int getEasyBotScore();
        void plusEasyBotScore();
        char do_choice(char& playersChoice);
    };

    class MediumBot
    {
    private:
        int MediumBotScore;

        const char vs_Scissors[6]{ 'p', 'p', 'p', 's', 'r', 'r' };
        const char vs_Rock[6]{ 's', 's', 's', 'r', 'p', 'p' };
        const char vs_Paper[6]{ 'r', 'r', 'r', 'p', 's', 's' };
    public:
        MediumBot();
        int getMediumBotScore();
        void plusMediumBotScore();
        char do_choice(char& playersChoice);
    };

    class HardBot
    {
    private:
        int HardBotScore;

        const char vs_Scissors[6]{ 'p', 'p', 's', 'r', 'r', 'r' };
        const char vs_Rock[6]{ 's', 's', 'r', 'p', 'p', 'p' };
        const char vs_Paper[6]{ 'r', 'r', 'p', 's', 's', 's' };

    public:
        HardBot();
        int getHardBotScore();
        void plusHardBotScore();
        char do_choice(char& playersChoice);
    };
}