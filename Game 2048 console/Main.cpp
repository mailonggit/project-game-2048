#include "Menu.h"


int main()
{
	resizeConsole(WidthConsole, HeightConsole);
	AnConTro();
	
	vector<Menu> listMenu;

	InMenu(listMenu);

	int dir = 0;
	bool CheckChoose = false;

	while (true)
	{
		DrawMenu();
		DrawText2048();

		PrintMenu(listMenu);

		TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

		MoveSelect(listMenu, dir, CheckChoose);

		if (CheckChoose == true)
		{
			CheckChoose = false;

			if (dir == 0) // PlayGame
			{
				system("cls");
				resizeConsole(WidthConsoleGame, HeightConsoleGame);
				AnConTro();

				int score = 0;
				bool endGame = false;
				int Val[4][4] = { 0 };

				DrawMap();

				setLocationFirst(Val);

				MainLoop(Val, score, endGame);

				if (endGame)
				{
					File(score);
					exit(0);
				}
				else
				{
					exit(0);
				}
			}
			else if (dir == 1)// hight score
			{
				system("cls");

				DrawMenu();
				DrawText2048();

				hightScore();

				system("cls");
			}
			else if (dir == 2) // Guide
			{
				system("cls");

				DrawMenu();
				DrawText2048();

				Guide();

				system("cls");
			}
			else if (dir == 3) // Info
			{
				system("cls");

				DrawMenu();
				DrawText2048();

				Info();

				system("cls");
			}
			else if (dir == 4) // exit
			{
				exit(0);
			}
		}
	}

	return 0;
}