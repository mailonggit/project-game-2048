#include <iostream>
using namespace std;
#include <time.h>
#include <conio.h>
#include <Windows.h>
//int board[4][4] = { { 2, 8, 2, 8 },{ 8, 4, 2, 0 },{ 4, 0, 0, 0 },
//{ 4, 0, 0, 0 } };
//int board[4][4] = { { 2, 2, 2, 0 },{ 2, 2, 0, 2 },{ 2, 0, 2, 2 },
//{ 0, 2, 2, 2 } };
//int board[4][4] = { { 2, 4, 2, 2 },{ 2, 2, 2, 4 },{ 2, 2, 4, 4 },
//{ 2, 4, 4, 2 } };
//case1
//2 8 2 8
//8 4 2 0
//4 0 0 0
//4 0 0 0
//case2
//2 2 2 0
//2 2 0 2
//2 0 2 2
//0 2 2 2
//case3
//2 4 2 2
//2 2 2 4
//2 2 4 4
//2 4 4 2
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
class Board
{
private:
	int i, j;
	/*int board[4][4]; = { { 2, 8, 2, 8 },{ 8, 4, 2, 0 },{ 4, 0, 0, 0 },
	{ 4, 0, 0, 0 } };*/
	int board[4][4];
public:
	void init()
	{
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				board[i][j] = 0;
			}
		}
		randomElement();
		randomElement();
	}
	void randomElement()
	{
		do
		{
			i = 0 + rand() % 4;
			j = 0 + rand() % 4;
		} while (board[i][j] != 0);
		board[i][j] = 2;
	}
	void moveDown(char x)
	{
		for (i = 0; i < 4; ++i)//on the row
		{
			for (j = 3; j >= 1; j--)//on the columm
			{
				for (int k = j - 1; k >= 0; k--)
				{

					if (board[j][i] == board[k][i] && board[j][i] != 0)
					{
						board[j][i] *= 2;
						board[k][i] = 0;
						break;
					}
					else
					{
						if (board[j][i] == 0 && board[k][i] != 0)
						{
							Swap(board[j][i], board[k][i]);
							//break;
						}
						else if (board[j][i] != 0 && board[k][i] != 0 && board[j][i] != board[k][i])
						{
							break;
						}

					}
				}
			}
		}
	}
	void moveUp(char x)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; ++j)
			{
				for (int k = j + 1; k < 4; ++k)
				{
					if (board[j][i] == board[k][i] && board[j][i] != 0)
					{
						board[j][i] *= 2;
						board[k][i] = 0;
						break;
					}
					else
					{
						if (board[j][i] == 0 && board[k][i] != 0)
						{
							Swap(board[j][i], board[k][i]);
						}
						else if (board[j][i] != 0 && board[k][i] != 0 && board[j][i] != board[k][i])
						{
							break;
						}
					}
				}
			}
		}
	}
	void moveLeft(char x)
	{
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				for (int k = j + 1; k < 4; ++k)
				{
					if (board[i][j] == board[i][k] && board[i][j] != 0)
					{
						board[i][j] *= 2;
						board[i][k] = 0;
						break;
					}
					else
					{
						if (board[i][j] == 0 && board[i][k] != 0)
						{
							Swap(board[i][j], board[i][k]);
						}
						else if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k])
						{
							break;
						}
					}
				}
			}
		}
	}
	void moveRight(char x)
	{
		for (i = 0; i < 4; ++i)
		{
			for (j = 3; j >= 1; j--)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (board[i][j] == board[i][k] && board[i][j] != 0)
					{
						board[i][j] *= 2;
						board[i][k] = 0;
						break;
					}
					else
					{
						if (board[i][j] == 0 && board[i][k] != 0)
						{
							Swap(board[i][j], board[i][k]);
						}
						else if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k])
						{
							break;
						}
					}
				}
			}
		}
	}
	public void redo() {
		if (!redo.isEmpty()) {
			board = redo.pop();
			undo.push(board);
		}
	}
	public void undo() {
		if (!undo.isEmpty() && undo.size() > 1) {
			board = undo.get(undo.size() - 1);
			redo.push(undo.pop());
		}
	}
	void update()
	{
		char x = _getch();
		if (x == 's')
		{
			moveDown(x);
			randomElement();
		}
		else if (x == 'w')
		{
			moveUp(x);
			randomElement();
		}
		else if (x == 'a')
		{
			moveLeft(x);
			randomElement();
		}
		else if (x == 'd')
		{
			moveRight(x);
			randomElement();
		}
	}
	void render()
	{
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl << endl;
		}
	}

};
//void randomElement(int i, int j)
//{
//	//do
//	//{
//		//random i, j
//		i = 0 + rand() % 4;
//		j = 0 + rand() % 4;
//	//} while (board[i][j] != 0);//if element in random location non-zero => random again							   //if element in random location is zero => element = 2
//	board[i][j] = 2;
//}
//void init()
//{
//	//initialize 0 for all elements
//	int i, j;
//	for (i = 0; i < 4; ++i)
//	{
//		for (j = 0; j < 4; ++j)
//		{
//			board[i][j] = 0;
//		}
//	}
//	randomElement(i, j);
//	randomElement(i, j);
//}

//void update()
//{
//	char x = _getch();
//	int i = 0, j = 0;
//	if (x == 's')
//	{
//		moveDown(x);
//		randomElement(i, j);
//	}
//	else if (x == 'w')
//	{
//		moveUp(x);
//		randomElement(i, j);
//	}
//	else if (x == 'a')
//	{
//		moveLeft(x);
//		randomElement(i, j);
//	}
//	else if (x == 'd')
//	{
//		moveRight(x);
//		randomElement(i, j);
//	}
//}
//void render()
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			cout << board[i][j] << "\t";
//		}
//		cout << endl << endl;
//	}
//}
int main()
{
	srand(time(NULL));
	Board b;
	b.init();
	while (true)
	{
		b.render();
		b.update();
		system("cls");
	}

	system("pause");
	return 0;
}
/*
public void redo() {
if (!redo.isEmpty()) {
board = redo.pop();
undo.push(board);
}
}



public void undo() {
if (!undo.isEmpty() && undo.size() > 1) {
board = undo.get(undo.size() - 1);
redo.push(undo.pop());
}*/
   
    
	