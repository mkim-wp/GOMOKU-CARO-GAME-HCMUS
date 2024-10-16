#include "Handle.h"

int CheckBoard(_POINT A[BOARD_SIZE][BOARD_SIZE], int pX, int pY)
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (A[i][j].x == pX && A[i][j].y == pY && A[i][j].c == 0)
			{
				if (_TURN == true) { A[i][j].c = -1; }
				else { A[i][j].c = 1; }
				return A[i][j].c;
			}
	return 0;
}

int row(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c)
			{
			case 1: if (A[i][j].c == 1 && A[i + 1][j].c == 1 && A[i + 2][j].c == 1 && A[i + 3][j].c == 1 && A[i + 4][j].c == 1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 1);
			}
				  else
			{
				t = 0;
			};
				  break;
			case-1: if (A[i][j].c == -1 && A[i + 1][j].c == -1 && A[i + 2][j].c == -1 && A[i + 3][j].c == -1 && A[i + 4][j].c == -1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 1);
			}
				  else
			{
				t = 0;
			};
				  break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int pole(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (j + 4 >= BOARD_SIZE)
				break;
			switch (A[i][j].c) {
			case 1: if (A[i][j].c == 1 && A[i][j + 1].c == 1 && A[i][j + 2].c == 1 && A[i][j + 3].c == 1 && A[i][j + 4].c == 1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 2);
			}
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i][j + 1].c == -1 && A[i][j + 2].c == -1 && A[i][j + 3].c == -1 && A[i][j + 4].c == -1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 2);
			}
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int diag1(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c) {
			case 1: if (A[i][j].c == 1 && A[i + 1][j + 1].c == 1 && A[i + 2][j + 2].c == 1 && A[i + 3][j + 3].c == 1 && A[i + 4][j + 4].c == 1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 3);
			}
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i + 1][j + 1].c == -1 && A[i + 2][j + 2].c == -1 && A[i + 3][j + 3].c == -1 && A[i + 4][j + 4].c == -1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 3);
			}
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int diag2(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c)
			{
			case 1: if (A[i][j].c == 1 && A[i - 1][j + 1].c == 1 && A[i - 2][j + 2].c == 1 && A[i - 3][j + 3].c == 1 && A[i - 4][j + 4].c == 1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 4);
			}
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i - 1][j + 1].c == -1 && A[i - 2][j + 2].c == -1 && A[i - 3][j + 3].c == -1 && A[i - 4][j + 4].c == -1)
			{
				t = 1;
				nhapnhay(A, A[i][j].c, i, j, 4);
			}
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}

int wingame(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	if (row(A) == 1 || pole(A) == 1 || diag1(A) == 1 || diag2(A) == 1) return 1;
	else return 0;
}
int matrixfull(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (A[i][j].c == 0) t = 0;
			if (t == 0) break;
		}
		if (t == 0) break;
	}
	return t;
}
int TestBoard(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	if (matrixfull(A) == 1 && wingame(A) != 1) return 0; // ma tran day
	else if (wingame(A) == 1)
		return (_TURN == true ? -1 : 1);
	else
		return 2;
}

int ProcessFinish(_POINT A[BOARD_SIZE][BOARD_SIZE], int pWhoWin, PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	GotoXY(0, A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin)
	{
		GotoXY(5, 5);
	case -1:
		PLAYER1.win++;
		PlaySound(0, 0, 0);
		Draw(3, 0, 30);
		DrawXwin();
		break;
	case 1:
		PLAYER2.win++;
		PlaySound(0, 0, 0);
		Draw(3, 0, 30);
		DrawOwin();
		break;
	case 0:
		PlaySound(0, 0, 0);
		Draw(3, 0, 30);
		DrawDraw();
		break;
	case 2:
		_TURN = !_TURN;
	}
	GotoXY(_X, _Y);
	return pWhoWin;
}

void init_cursor_board(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	TextColor(240);
	GotoXY(_X, _Y);
	std::cout << cursor_char;
}

void MoveRight(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	TextColor(255);
	GotoXY(_X, _Y);
	if (A[(_X - 5) / 4][(_Y - 2) / 2].c == 0)
	{
		std::cout << " ";
	}
	if (_X < A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	TextColor(255);
	GotoXY(_X, _Y);
	if (A[(_X - 5) / 4][(_Y - 2) / 2].c == 0)
	{
		std::cout << " ";
	}
	if (_X > A[0][0].x)
	{
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	TextColor(255);
	GotoXY(_X, _Y);
	if (A[(_X - 5) / 4][(_Y - 2) / 2].c == 0)
	{
		std::cout << " ";
	}
	if (_Y < A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	TextColor(255);
	GotoXY(_X, _Y);
	if (A[(_X - 5) / 4][(_Y - 2) / 2].c == 0)
	{
		std::cout << " ";
	}
	/*else if (A[(_X - 5) / 4][(_Y - 2) / 2].c == -1)
	{
		TextColor(Color_X);
		std::cout << "x";
	}
	else if (A[(_X - 5) / 4][(_Y - 2) / 2].c == 1)
	{
		TextColor(Color_O);
		std::cout << "o";
	}*/
	if (_Y > A[0][0].y)
	{
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}
