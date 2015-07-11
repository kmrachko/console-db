#if !defined(MY_WINDOW_H)

#define MY_WINDOW_H

#include "fun_console.h"
#include <stdio.h>
#include <string>
using namespace std;
struct Tovar {
	string Name;
	string Supplier;
	int Quantity;
	friend bool operator ==(Tovar const & a, Tovar const & b) {
		if (a.Name==b.Name||a.Quantity==b.Quantity||a.Supplier==b.Supplier) return 1;
		return 0;
	}
};
class Window {
protected:
	int BorderType;
	int x1, y1;
	int x2, y2;
	int BorderColor, BackColor;
public:
	Window(int x1_=0,int y1_=0, int x2_=79,int y2_=25,int bcolor=15, int fcolor=9);
	virtual int DrawBorder(int btype=0);
};
#endif