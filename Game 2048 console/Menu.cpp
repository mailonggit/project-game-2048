#include "Menu.h"


void mButton()
{
	AnConTro();
	int Check;
	do {
		gotoxy(70, 19);
		cout << " 1: Back ";
		if (_kbhit())
		{
			Check = _getch();
			if (Check == 49)
				break;
		}
	} while (true);
}

void InMenu(vector<Menu> &listMenu)
{
	Menu items;

	items.x = 35;
	items.y = 10;
	items.data = "Play Game";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 12;
	items.data = "Score";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 14;
	items.data = "Guide";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 16;
	items.data = "Info";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 18;
	items.data = "Quit";
	listMenu.push_back(items);
}

void PrintMenu(vector<Menu> listMenu)
{
	for (int i = 0; i < listMenu.size(); i++)
	{
		gotoxy(listMenu[i].x, listMenu[i].y); cout << listMenu[i].data;
	}
}

void MoveSelect(vector<Menu> listMenu, int &dir, bool &Check)
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 72) // UP
			{
				gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << "             ";
				gotoxy(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0)
				{
					dir = listMenu.size() - 1;
				}
				else
					dir--;

				TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

				break;
			}
			else if (key == 80) // DOWN
			{
				gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << "             ";
				gotoxy(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;

				if (dir == listMenu.size() - 1)
				{
					dir = 0;
				}
				else
					dir++;

				TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

				break;
			}
			else if (key == 13) // ENTER
			{
				Check = true;
				break;
			}
		}
	}
}

void Guide()
{
	ifstream FileIn("fileData\\TextGame.dll", ios::in);
    
	if (FileIn.fail())
	{
		cout << "File ERROR";
		Sleep(5000);
		exit(0);
	}
	int line = 10;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
			break;
		gotoxy(10, line++); ColorText(text, 10);
	}
	FileIn.close();

	mButton();
}

void Info()
{

	ifstream FileIn("fileData\\TextGame.dll", ios::in);
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
		{
			break;
		}
	}
	int line = 11;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		gotoxy(20, line++); ColorText(text, 10);
	}
	FileIn.close();

	mButton();
}

void hightScore()
{
	string name; int score;

	ifstream FileIn("fileData\\hightScore.in", ios::in);
	TextColor(4);
	gotoxy(33, 10); cout << "HIGHT SCORE:" << endl;

	if (FileIn.fail())
	{
		gotoxy(35, 12);    cout << "EMPTY." << endl;
	}
	else
	{
		int x = 0, i = 12;
		while (x < 5)
		{
			FileIn >> name >> score;
			gotoxy(28, i = i + 1);   cout << name;
			gotoxy(50, i);   cout << score;
			x++;
		}
	}

	mButton();
}