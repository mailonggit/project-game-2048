#pragma once
#include "Graphics.h"


typedef struct Score
{
	string name;
	int score;
}SCORE;

void permutation(SCORE &, SCORE &);
void arrange(vector<SCORE> &);
void File(int);
void hightScore();
