//#include "stdafx.h"
#include <windows.h>
#include "fun_console.h"
#include <stdlib.h>


void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void SetColor(int textcolor, int bkcolor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		(WORD)((bkcolor << 4) | textcolor));
}

void SetSize(int X, int Y)
{
    COORD coord = { X, Y };
	SMALL_RECT src = {0, 0, X-1, Y-1};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	SetConsoleWindowInfo (GetStdHandle (STD_OUTPUT_HANDLE),1, &src);

}

int GetRows()
{
	CONSOLE_SCREEN_BUFFER_INFO c;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c))
		return 0;
	return c.dwSize.Y;
}

int GetCols()
{
	CONSOLE_SCREEN_BUFFER_INFO c;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c))
		return 0;
	return c.dwSize.X;
}

int GetCurrentY()
{
	CONSOLE_SCREEN_BUFFER_INFO c;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c))
		return 0;
	return c.dwCursorPosition.Y;
}

int GetCurrentX()
{
	CONSOLE_SCREEN_BUFFER_INFO c;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c))
		return 0;
	return c.dwCursorPosition.X;
}

void ShowCaret(BOOL show)
{
	CONSOLE_CURSOR_INFO CCI;
    CCI.bVisible=false;
    CCI.dwSize=99;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CCI);
}

void cls()
{
	system("cls");
}

