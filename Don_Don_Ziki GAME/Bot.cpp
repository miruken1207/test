#include "Bot.h"

bot::EasyBot::EasyBot()
{
	this->EasyBotScore = 0;
}
int bot::EasyBot::getEasyBotScore()
{
	return this->EasyBotScore;
}
void bot::EasyBot::plusEasyBotScore()
{
	++(this->EasyBotScore);
}
char bot::EasyBot::do_choice(char& playersChoice)
{
	srand(time(NULL));
	int rand_choice;
	rand_choice = rand() % (5 - 0 + 1) + 0;
	switch (playersChoice)
	{
	case 's':
		return vs_Scissors[rand_choice];
	case 'r':
		return vs_Rock[rand_choice];
	case 'p':
		return vs_Paper[rand_choice];
	}
	return ' ';
}



bot::MediumBot::MediumBot()
{
	this->MediumBotScore = 0;
}
int bot::MediumBot::getMediumBotScore()
{
	return this->MediumBotScore;
}
void bot::MediumBot::plusMediumBotScore()
{
	++(this->MediumBotScore);
}
char bot::MediumBot::do_choice(char& playersChoice)
{
	int rand_choice;
	rand_choice = rand() % (5 - 0 + 1) + 0;
	switch (playersChoice)
	{
	case 's':
		return vs_Scissors[rand_choice];
	case 'r':
		return vs_Rock[rand_choice];
	case 'p':
		return vs_Paper[rand_choice];
	}
	return ' ';
}



bot::HardBot::HardBot()
{
	this->HardBotScore = 0;
}
int bot::HardBot::getHardBotScore()
{
	return this->HardBotScore;
}
void bot::HardBot::plusHardBotScore()
{
	++(this->HardBotScore);
}
char bot::HardBot::do_choice(char& playersChoice)
{
	int rand_choice;
	rand_choice = rand() % (5 - 0 + 1) + 0;
	switch (playersChoice)
	{
	case 's':
		return vs_Scissors[rand_choice];
	case 'r':
		return vs_Rock[rand_choice];
	case 'p':
		return vs_Paper[rand_choice];
	}
	return ' ';
}
