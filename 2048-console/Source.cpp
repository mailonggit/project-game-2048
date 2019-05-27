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
package com.hackbulgaria.corejava;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Stack;

public class Game implements Serializable {

    private static final long serialVersionUID = 1L;
    private final int boardDimensions = 4;
    private int[][] board = new int[boardDimensions][boardDimensions];
    private Stack<int[][]> undo = new Stack<>();
    private Stack<int[][]> redo = new Stack<>();

    public Game() {
        placeRandomNumber();
        placeRandomNumber();
        undo.push(board);
        board = cloneBoard();
    }

    private int[][] cloneBoard() {
        int[][] newArray = new int[boardDimensions][boardDimensions];
        for (int i = 0; i < boardDimensions; i++) {
            for (int j = 0; j < boardDimensions; j++) {
                newArray[i][j] = board[i][j];
            }
        }
        return newArray;
    }

    private void createNewList(List<Integer> currentList, List<Integer> newList) {
        if (!currentList.isEmpty()) {
            for (int i = 0; i < currentList.size(); i++) {
                if (i < currentList.size() - 1 && currentList.get(i).equals(currentList.get(i + 1))) {
                    newList.add(currentList.get(i) * 2);
                    currentList.remove(i + 1);
                    currentList.add(0);
                } else {
                    newList.add(currentList.get(i));
                }
            }
        }
    }

    public int[][] getBoard() {
        return board;
    }

    public boolean hasZeroElements() {

        for (int i = 0; i < boardDimensions; i++) {
            for (int j = 0; j < boardDimensions; j++) {
                if (board[i][j] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isLost() {
        if (hasZeroElements()) {
            return false;
        } else {
            for (int x = 0; x < boardDimensions; x++) {
                for (int y = 0; y < boardDimensions - 1; y++) {
                    if (board[x][y] == board[x][y + 1]) {
                        return false;
                    }
                }
            }
            for (int y = 0; y < boardDimensions; y++) {
                for (int x = 0; x < boardDimensions - 1; x++) {
                    if (board[x][y] == board[x + 1][y]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public void moveDown() {
        List<Integer> column = new ArrayList<>();
        List<Integer> newColumn = new ArrayList<>();
        for (int y = 0; y < boardDimensions; y++) {
            column.clear();
            newColumn.clear();
            for (int x = boardDimensions - 1; x >= 0; x--) {
                if (board[x][y] != 0) {
                    column.add(board[x][y]);
                }
            }
            createNewList(column, newColumn);
            for (int x = boardDimensions - 1; x >= 0; x--) {
                if (!newColumn.isEmpty()) {
                    board[x][y] = newColumn.get(0);
                    newColumn.remove(0);
                } else {
                    board[x][y] = 0;
                }
            }
        }
        placeNumber();
    }

    public void moveLeft() {
        List<Integer> row = new ArrayList<>();
        List<Integer> newRow = new ArrayList<>();
        for (int x = 0; x < boardDimensions; x++) {
            row.clear();
            newRow.clear();
            for (int y = 0; y < boardDimensions; y++) {
                if (board[x][y] != 0) {
                    row.add(board[x][y]);
                }
            }
            createNewList(row, newRow);
            for (int y = 0; y < boardDimensions; y++) {
                if (!newRow.isEmpty()) {
                    board[x][y] = newRow.get(0);
                    newRow.remove(0);
                } else {
                    board[x][y] = 0;
                }
            }
        }
        placeNumber();
    }

    public void moveRight() {
        List<Integer> row = new ArrayList<>();
        List<Integer> newRow = new ArrayList<>();
        for (int x = 0; x < boardDimensions; x++) {
            row.clear();
            newRow.clear();
            for (int y = boardDimensions - 1; y >= 0; y--) {
                if (board[x][y] != 0) {
                    row.add(board[x][y]);
                }
            }
            createNewList(row, newRow);
            for (int y = boardDimensions - 1; y >= 0; y--) {
                if (!newRow.isEmpty()) {
                    board[x][y] = newRow.get(0);
                    newRow.remove(0);
                } else {
                    board[x][y] = 0;
                }
            }
        }
        placeNumber();
    }

    public void moveUp() {
        List<Integer> column = new ArrayList<>();
        List<Integer> newColumn = new ArrayList<>();
        for (int y = 0; y < boardDimensions; y++) {
            column.clear();
            newColumn.clear();
            for (int x = 0; x < boardDimensions; x++) {
                if (board[x][y] != 0) {
                    column.add(board[x][y]);
                }
            }
            createNewList(column, newColumn);
            for (int x = 0; x < boardDimensions; x++) {
                if (!newColumn.isEmpty()) {
                    board[x][y] = newColumn.get(0);
                    newColumn.remove(0);
                } else {
                    board[x][y] = 0;
                }
            }
        }
        placeNumber();
    }

    private void placeNumber() {
        if (!undo.isEmpty()) {
            if (!Arrays.deepEquals(undo.peek(), board)) {
                if (hasZeroElements()) {
                    placeRandomNumber();
                    undo.push(board);
                    board = cloneBoard();
                }
                else if (!hasZeroElements() && !isLost()) {
                    undo.push(board);
                    board = cloneBoard();
                }
            }
        }
        else {
            placeRandomNumber();
        }
    }

    private void placeRandomNumber() {
        int number;
        Random random = new Random();
        int randomX = random.nextInt(boardDimensions);
        int randomY = random.nextInt(boardDimensions);
        int randomNum = random.nextInt(99);
        if (randomNum < 90) {
            number = 2;
        } else {
            number = 4;
        }
        if (board[randomX][randomY] == 0) {
            board[randomX][randomY] = number;
        } else {
            placeRandomNumber();
        }
    }

    public void redo() {
        if (!redo.isEmpty()) {
            board = redo.pop();
            undo.push(board);
        }
    }

    public void setBoard(int[][] newBoard) {
        this.board = newBoard;
    }

    public void undo() {
        if (!undo.isEmpty() && undo.size() > 1) {
            board = undo.get(undo.size() - 1);
            redo.push(undo.pop());
        }
    }
	}