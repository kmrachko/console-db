#if !defined(MY_CONSOLE_H)

#define MY_CONSOLE_H

#include <windows.h>

enum ConsoleColor
{
	Black         = 0,
	Blue          = 1,
	Green         = 2,
	Cyan          = 3,
	Red           = 4,
	Magenta       = 5,
	Brown         = 6,
	LightGray     = 7,
	DarkGray      = 8,
	LightBlue     = 9,
	LightGreen    = 10,
	LightCyan     = 11,
	LightRed      = 12,
	LightMagenta  = 13,
	Yellow        = 14,
	White         = 15
};

void GotoXY(int X, int Y);
void SetColor(int textcolor, int bkcolor);
void SetSize(int X, int Y);
int GetRows();
int GetCols();
int GetCurrentY();
int GetCurrentX();
void ShowCaret(BOOL show=TRUE);
void cls();

#endif
