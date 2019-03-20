#include "Draw.h"


void DrawMenu()
{
	for (int i = 0; i <= HeightMenu; i++)
	{
		for (int j = 0; j <= WidthMenu; j++)
		{
			if (i == 0 || i == HeightMenu || j == 0 || j == WidthMenu)
			{
				gotoxy(j, i); cout << char(219);
			}
		}
	}
}

void DrawText2048()
{
	ifstream FileIn("fileData\\Text.IN", ios::in);

	if (FileIn.fail())
	{
		cout << "ERROR file Text.";
		Sleep(5000);
		exit(0);
	}

	int line = 1;
	while (!FileIn.eof())
	{
		gotoxy(20, line++);
		string text;
		getline(FileIn, text);
		if (text == "**")
			break;
		else
		  cout << text << endl;
	}


}

void drawIcon()
{
	ifstream FileIn("fileData\\Text.IN", ios::in);

	if (FileIn.fail())
	{
		cout << "ERROR file Text.";
		Sleep(5000);
		exit(0);
	}

	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
			break;
	}

	int line = 6;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		gotoxy(WidthGame + 2, line++); ColorText(text, 12);
	}

}

void DrawMap()
{
	char dmap = 219;
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (i == 0 || i == 16 || j == 0 || j == 28 || i == 4 || i == 8 || i == 12 || j == 7 || j == 14 || j == 21)
				ColorText(dmap, 8);
			else
				ColorText(dmap, 7);
		}
		cout << endl;
	}

	//draw box score
	for (int i = 0; i <= 4; i++)
	{
		for (int j = WidthGame; j <= WidthGame + 15; j++)
		{
			if (i == 0 || i == 4 || j == WidthGame + 15)
			{
				gotoxy(j, i); cout << (char)219;
			}
		}
	}

	//draw icon next box game
	drawIcon();
}

void Draw(int x, int y, int data)
{
	char dmap = 219;
	int columnSubtraction = 0, tColor = 15, bgColor = 7;

	if (data == 0)
	{
		bgColor = 7;
	}
	else if (data == 2)
	{
		bgColor = 1;
	}
	else if (data == 4)
	{
		bgColor = 22;
	}
	else if (data == 8)
	{
		bgColor = 2;
	}
	else
	{
		int Sum = 8;
		columnSubtraction = 1;
		for (int i = 3; i <= 10; i++)
		{
			Sum *= 2;
			if (Sum == data)
			{
				if (i <= 4) // 16 32 
				{
					bgColor = i;
					break;
				}
				else if (i == 5) //64
				{
					bgColor = i + 1;
					break;
				}
				else if (i > 5 && i <= 8) // 128 256 512
				{
					bgColor = i + 3;
					break;
				}
				else // 1024 2048
				{
					bgColor = i + 3;
					columnSubtraction++;
					break;
				}
			}
		}
	}

	//Tô lại màu của ô đó theo data.
	for (int line = y - 1; line <= y + 1; line++)
	{
		for (int column = x - 3; column <= x + 2; column++)
		{
			gotoxy(column, line);  ColorText(dmap, bgColor);
		}
	}

	if (data > 0)
	{
		gotoxy(x - columnSubtraction, y);  
		setBGColor(bgColor); ColorText(data, tColor); setBGColor(0);
	}
}

void DrawVal(int Val[][4])
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			Draw((j * 7) + 4, (i * 4) + 2, Val[i][j]); //Công thức di con trỏ đúng đến vị trí cần in trên map.
		}
	}
}