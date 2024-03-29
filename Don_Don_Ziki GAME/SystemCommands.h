#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

void Input(char& key);
void Clear();
void Error();
void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

void RED();
void YELLOW();
void GREEN();
void PURPLE();
void WHITE();
void GRAY();
void BLACK();

void FRAME();
void GameZoneFRAME();

void RockOutPlayer();
void RockOutBot();

void ScissorsOutPlayer();
void ScissorsOutBot();

void PaperOutPlayer();
void PaperOutBot();

void UnkownOutBot();
