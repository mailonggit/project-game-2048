#pragma once
#include "Draw.h"
#include "Location.h"
#include "File.h"

enum Status { LEFT, RIGHT, UP, DOWN, EMPTY };

void MoveNum(Status statusMove, int Val[][4], int &score, bool &endGame);

void MainLoop(int Val[][4], int &score, bool &endGame);
