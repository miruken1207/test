#include <iostream>

#include "Animation.h"
#include "Menu.h"
#include "SystemCommands.h"
#include "Player.h"

using namespace std;

int main()
{
	ConsoleCursorVisible(false, 100);

	int start = 0;
	MENU(start);

	return 0;
}
