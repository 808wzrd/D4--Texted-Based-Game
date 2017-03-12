//qweqwe
#include<iostream>
#include<conio.h>
#include<windows.h>
using std::cout;
using std::endl;

bool gameOver;

const int width = 30;
const int height = 20;

int x, y;
int enemyX, enemyY;

enum hDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
hDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;

	enemyX = rand() % width;
	enemyY = rand() % height;

}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "|";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			if (k == 0)
				cout << "|";
			if (i == y && k == x)
				cout << "O";
			else if (i == enemyY && k == enemyX)
				cout << "E";
			else
				cout << " ";
			if (k == width - 1)
				cout << "|";
		}
		cout << endl;
	}





	for (int i = 0; i < width + 2; i++)
		cout << "|";
	cout << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'q':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x == enemyX && y == enemyY)
	{
		gameOver = true;

	}
	//f (x == | && y == | )
	//{
	//	gameOver = true;
	//}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(75);
	}
}