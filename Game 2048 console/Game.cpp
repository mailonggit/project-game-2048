#include "Game.h"

void MoveNum(Status statusMove, int Val[][4], int &score, bool &endGame)
{
	if (statusMove == LEFT)
	{
		for (int line = 0; line < 4; line++)
		{
			for (int reCheck = 1; reCheck < 4; reCheck++)
			{
				for (int column = reCheck - 1; column >= 0; column--)
				{
					if (Val[line][column] == 0 || Val[line][column] == Val[line][column + 1])
					{
						if (Val[line][column] == Val[line][column + 1])
						{
							score += Val[line][column + 1];
							//PlaySoundA("Correct_Score.wav", NULL, 0x0000);
						}
						Val[line][column] += Val[line][column + 1];
						Val[line][column + 1] = 0;
					}
				}
			}
		}
		randLocationLate(Val, endGame);
	}
	else if (statusMove == RIGHT)
	{
		for (int line = 0; line < 4; line++)
		{
			for (int reCheck = 2; reCheck >= 0; reCheck--)
			{
				for (int column = reCheck + 1; column < 4; column++)
				{
					if (Val[line][column] == 0 || Val[line][column] == Val[line][column - 1])
					{
						if (Val[line][column] == Val[line][column - 1])
						{
							score += Val[line][column - 1];
							//PlaySoundA("Correct_Score.wav", NULL, 0x0000);
						}
						Val[line][column] += Val[line][column - 1];
						Val[line][column - 1] = 0;
					}
				}
			}
		}
		randLocationLate(Val, endGame);
	}
	else if (statusMove == UP)
	{
		for (int column = 0; column < 4; column++)
		{
			for (int reCheck = 1; reCheck < 4; reCheck++)
			{
				for (int line = reCheck - 1; line >= 0; line--)
				{
					if (Val[line][column] == 0 || Val[line][column] == Val[line + 1][column])
					{
						if (Val[line][column] == Val[line + 1][column])
						{
							score += Val[line + 1][column];
							//PlaySoundA("Correct_Score.wav", NULL, 0x0000);
						}
						Val[line][column] += Val[line + 1][column];
						Val[line + 1][column] = 0;
					}
				}
			}
		}
		randLocationLate(Val, endGame);
	}
	else if (statusMove == DOWN)
	{
		for (int column = 0; column < 4; column++)
		{
			for (int reCheck = 2; reCheck >= 0; reCheck--)
			{
				for (int line = reCheck + 1; line < 4; line++)
				{
					if (Val[line][column] == 0 || Val[line][column] == Val[line - 1][column])
					{
						if (Val[line][column] == Val[line - 1][column])
						{
							score += Val[line - 1][column];
							//PlaySoundA("Correct_Score.wav", NULL, 0x0000);
						}
						Val[line][column] += Val[line - 1][column];
						Val[line - 1][column] = 0;
					}
				}
			}
		}
		randLocationLate(Val, endGame);
	}
	gotoxy(30, 2); cout << "SCORE: " << score;
	//PlaySoundA("Correct_Score.wav", NULL, 0x0000);
}

void MainLoop(int Val[][4], int &score, bool &endGame)
{
	Status statusMove = EMPTY;
	while (!endGame)
	{
		MoveNum(statusMove, Val, score, endGame);
		DrawVal(Val);

		statusMove = EMPTY;
		if (_kbhit())
		{
			int key = _getch();
			if (key == 75)
				statusMove = LEFT;
			else if (key == 77)
				statusMove = RIGHT;
			else if (key == 72)
				statusMove = UP;
			else if (key == 80)
				statusMove = DOWN;
			else if (key == 27) // ESC => exit.
			{
				break;
			}
		}
	}
}