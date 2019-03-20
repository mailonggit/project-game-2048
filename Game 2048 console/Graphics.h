#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define WidthConsole            700
#define HeightConsole           400
#define WidthConsoleGame        400
#define HeightConsoleGame       320
#define WidthGame               29
#define HeightGame              17
#define WidthMenu               80
#define HeightMenu              20


void gotoxy(int x, int y);
void TextColor(WORD color);
void setBGColor(WORD);
void resizeConsole(int width, int height);
void clrscr();
void AnConTro();
void HienConTro();
void ColorText(int, int);
void ColorText(char, int);
void ColorText(string, int);
