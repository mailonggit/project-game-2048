#pragma once

#include "Game.h"

struct Menu
{
	int x, y;
	string data;
};

void InMenu(vector<Menu> &listMenu);
void PrintMenu(vector<Menu> listMenu);
void MoveSelect(vector<Menu> listMenu, int &dir, bool &Check);
void Guide();
void Info();
void hightScore();