#include "print_vec.h"

DialogWindow::DialogWindow(int width, int height,string caption) {
	this->width=width;
	this->height=height;
	Valign=(GetRows()-height-2)/2;
	Halign=(GetCols()-width-2)/2;
	x1=1+Halign;
	y1=1+Valign;
	x2=2+Halign+width;
	y2=2+Valign+height;
	BorderColor=4;
	BackColor=7;
	this->caption=caption;
}
int DialogWindow::DrawBorder() {
	SetColor(BorderColor,BackColor);
	char ltop, rtop, vline, gline, rbot, lbot;
	ltop=218;
	rtop=191;
	gline=196;
	vline=179;
	lbot=192;
	rbot=217;
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
			if (i>x1 && i<x2)
			{

				printf("%c",' ');
				SetConsoleOutputCP(866);
			}
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
	int talign=(width-caption.length())/2;
	Window title(x1+talign,y1,x1+talign+caption.length()+1,y1+3,4,7);
	title.DrawBorder(1);
	GotoXY(x1+talign+1,y1+1);
	printf("%s",caption.c_str());
	SetConsoleOutputCP(866);
	return 1;
}
int DialogWindow::GetTop() {
	return y1;
}
int DialogWindow::GetLeft() {
	return x1;
}

DrawVector::DrawVector(int x1, int y1, int x2, int y2, vector <Tovar> *bd1):Window(x1, y1, x2-2, y2) {
	size = (y2 - y1)/2-2;
	bd=bd1;
}
int DrawVector::DrawBorder(int cur,int focus) {
	SetConsoleOutputCP(866);
	char ltop, rtop, vline, gline, rbot, lbot;
	if (!focus) SetColor(BorderColor, BackColor);
	else SetColor(0, 7);
	/*if (BorderType==1) {
		ltop=218;
		rtop=191;
		gline=196;
		vline=179;
		lbot=192;
		rbot=217;
	}*/
	ltop=201;
	rtop=187;
	gline=205;
	vline=186;
	lbot=200;
	rbot=188;
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
	
	int max = (size>bd->size())?bd->size():size;
	int h=0;


	vline=179;
	if (!focus) SetColor(11, BackColor);
	else SetColor(4, 7);

	GotoXY(x1+1,y1+(h*2)+1);
	printf("Name");
	GotoXY(x1+(x2-x1)/3+2,y1+(h*2)+1);
	printf("Supplier");
	GotoXY(x1+2*(x2-x1)/3+2,y1+(h*2)+1);
	printf("Number");
	if (!focus) SetColor(BorderColor, BackColor);
	else SetColor(0, 7);
	SetConsoleOutputCP(866);
	GotoXY(x1+(x2-x1)/3,y1+(h*2)+1);
	printf("|",vline);
	GotoXY(x1+2*(x2-x1)/3,y1+(h*2)+1);
	printf("|",vline);
	GotoXY(x1+1,y1+(h*2)+2);
	for (int i=x1;i<x2-1;i++)
		printf("%c",gline);
	gline=196;
	if (bd->size()==0)
	{
		GotoXY(x1+1,y1+3);
		printf("Database is empty");
		SetConsoleOutputCP(866);
		return 1;
	}
	for (int i=cur,h=1;i<(max+cur);i++,h++)
	{
		GotoXY(x1+1,y1+(h*2)+1);
		printf("%s",bd->at(i).Name.c_str());
		GotoXY(x1+(x2-x1)/3+2,y1+(h*2)+1);
		printf("%s",bd->at(i).Supplier.c_str());
		GotoXY(x1+2*(x2-x1)/3+2,y1+(h*2)+1);
		printf("%d",bd->at(i).Quantity);
		SetConsoleOutputCP(866);
		GotoXY(x1+(x2-x1)/3,y1+(h*2)+1);
		printf("|",vline);
		GotoXY(x1+2*(x2-x1)/3,y1+(h*2)+1);
		printf("|",vline);
		GotoXY(x1+1,y1+(h*2)+2);
		for (int g=x1;g<x2-1;g++)
			printf("%c",gline);
	}
	int b=0;
	if(bd->size()>size)
	{
		for (h=0;h<=size*2+3;h++)
		{
			GotoXY(x2+1,y1+h);
			printf("%c",177);
		}
		double per=1.*size/bd->size()*size*2;
		double start=1.*cur/bd->size()*size*2;
		for (b=ceil(start);b<ceil(per+start)+4;b++)
		{
			GotoXY(x2+1,y1+b);
			printf("%c",219);
		}
	}
	return 1;
}
int DrawVector::GetSize() {
	return size;
}