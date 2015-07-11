#include "window.h"
Window::Window(int x1_,int y1_, int x2_,int y2_,int bcolor, int fcolor) {
	(x1_>=0)?x1=x1_:x1=0;
	(y1_>=0)?y1=y1_:y1=0;
	(x2_>x1)?x2=x2_:x2=79;
	(y2_>y1)?y2=y2_:y2=25;
	(bcolor>=0 && bcolor<=15)?BorderColor=bcolor:BorderColor=15;
	(fcolor>=0 && fcolor<=15)?BackColor=fcolor:BackColor=9;
	BorderType=1;
}
int Window::DrawBorder(int btype) {
	if (btype) BorderType=btype;
	char ltop, rtop, vline, gline, rbot, lbot;
	SetColor(BorderColor, BackColor);
	if (BorderType==1) {
		ltop=218;
		rtop=191;
		gline=196;
		vline=179;
		lbot=192;
		rbot=217;
	}
	if (BorderType==2) {
		ltop=201;
		rtop=187;
		gline=205;
		vline=186;
		lbot=200;
		rbot=188;
	}
	GotoXY(x1,y1);
	for (int i=x1;i<=x2;i++)
		{
			if (i==x1) printf("%c",ltop);
			if (i>x1 && i<x2) printf("%c",gline);
			if (i==x2) printf("%c",rtop);
		}
	int j=0;
	while (j!=y2-y1-2)
	{
		GotoXY(x1,y1+ ++j);
		for (int i=x1;i<=x2;i++)
		{
			if (i==x1) printf("%c",vline);
			if (i>x1 && i<x2) printf(" ");
			if (i==x2) printf("%c",vline);
		}

	}
	GotoXY(x1,y2-1);
	for (int i=x1;i<=x2;i++)
		{
			if (i==x1) printf("%c",lbot);
			if (i>x1 && i<x2) printf("%c",gline);
			if (i==x2) printf("%c",rbot);
		}
	return 1;
}