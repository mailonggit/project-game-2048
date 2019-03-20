#include "Location.h"

//Random vi trị đầu tiên của 2 số.
void setLocationFirst(int Val[][4])
{
	int xFirst, yFirst, xSecond, ySecond;
	srand(time(0));
	xFirst = rand() % 4;		// Random 2 vi tri cua so dau tien
	yFirst = rand() % 4;

	do {
		xSecond = rand() % 4;		//Random 2 vi tri cua so thu hai
		ySecond = rand() % 4;
	} while (xFirst == xSecond || yFirst == ySecond);

	Val[xFirst][yFirst] = 2;
	Val[xSecond][ySecond] = 2;
}

void randLocationLate(int Val[][4], bool &endGame)
{
	int checkNum = 0;
	for (int line = 0; line < 4; line++) // Đếm số chỗ trống
	{
		for (int column = 0; column < 4; column++)
		{
			if (Val[line][column] == 0)
				checkNum++;
		}
	}

	if (checkNum >= 1) // có nhiều hơn 1 or có 1 chỗ trống.
	{
		int posx, posy;
		srand(time(0));
		do
		{
			posx = rand() % (4);
			posy = rand() % (4);
		} while (Val[posx][posy] != 0);

		int randVal = rand() % 101; // random value them vao. 75% 2, 25% 4;
		if (randVal <= 75)
			Val[posx][posy] = 2;
		else
			Val[posx][posy] = 4;
	}
	else  // hết chỗ trống
		endGame = true;
}
