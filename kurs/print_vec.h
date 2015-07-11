#if !defined(MY_PRINT_VEC_H)
#define MY_PRINT_VEC_H
#include "window.h"
#include <vector>
class DialogWindow : private Window {
private:
	int Valign,Halign;
	string caption;
	int width, height;
public:
	DialogWindow(int,int,string);
	int DrawBorder();
	int GetTop();
	int GetLeft();
};
class DrawVector : private Window {
private:
	int size;
	vector <Tovar> *bd;
public:
	DrawVector(int,int,int,int,vector <Tovar> *bd1);
	int DrawBorder(int,int);
	int GetSize();
};
#endif