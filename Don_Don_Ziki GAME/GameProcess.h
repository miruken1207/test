#pragma once

#include "SystemCommands.h"
#include "Player.h"
#include "Bot.h"
#include "Menu.h"


int GameProcess(int& difficulty, int& roundsCount);
int Play_vs_E(int& roundsCount);
char Check_PvE(plr::Player& player, bot::EasyBot& eBot, char& playersChoice, char& ebotsChoice);
int Play_vs_M(int& roundsCount);
char Check_PvM(plr::Player& player, bot::MediumBot& mBot, char& playersChoice, char& mBotsChoice);
int Play_vs_H(int& roundsCount);
char Check_PvH(plr::Player& player, bot::HardBot& hBot, char& playersChoice, char& hBotsChoice);