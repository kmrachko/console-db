#include "main_menu.h"
using namespace std;
// ---------Класс пунктов меню-------------
MenuItem::MenuItem(int x1, int y1, int x2, int y2, int bcolor, int fcolor, string item_name, void(*item_action)(vector<Tovar>&)):Window(x1,y1,x2,y2,bcolor,fcolor){
	this->item_name=item_name;
	this->item_action=item_action;
	this->selected=false;
}
void MenuItem::UseItem(vector<Tovar>& baza) {
	this->item_action(baza);
}
void MenuItem::SetSelected(bool set) {
	this->selected=set;
}

int MenuItem::DrawBorder(int align, bool& key, int focus) {
	int l=0;
	char ltop, rtop, vline, gline, rbot, lbot;
	if (!selected) 
	{
		if(!focus) SetColor(BorderColor, BackColor);
		else SetColor(0, 7);
		BorderType=1;
	}
	else 
	{
		SetColor(0, 8);
		BorderType=2;
	}
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
	if (key) x1+=align;
	if (key) x2+=align;
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
	
				printf("%c",this->item_name[l++]);
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
	return 1;
}
// --------Класс-контейнер для пунктов меню--------------
MainMenu::MainMenu(){
	CurX=2;
	CurY=2;
	menu_sel=0;
	maxW=CurX;
	align=0;
	this->key=true;
}
int MainMenu::GetCount(){
	return items.size();
}
void MainMenu::AddMenu(string name, void(*act)(vector<Tovar>&)) {
	if ((CurX+1+name.length())>79)
	{
		CurY+=3;
		CurX=2;
	}
	int x = CurX+1+name.length();
	MenuItem TempItem(CurX,CurY,x,CurY+3,15,9,name,act);
	CurX=x+1;
	maxW=(CurX>maxW)?CurX:maxW;
	items.push_back(TempItem);
	items[0].SetSelected(true);
}
void MainMenu::Redraw(int focus) {
	align=(GetCols()-(maxW-2))/2; //magic
	if (!focus)
	{
		Window b(align,1,maxW+align,CurY+4);
		b.DrawBorder(1);
	}
	else
	{
		Window b(align,1,maxW+align,CurY+4,0,7);
		b.DrawBorder(1);
	}
	for (int i=0;i<items.size();i++)
		items[i].DrawBorder(align,key,focus);
	this->key=false;
}
void MainMenu::Select(int i) {
	items[menu_sel].SetSelected(false);
	items[i].SetSelected(true);
	menu_sel=i;
}
void MainMenu::UseMenu(vector<Tovar>& base) {
	items[menu_sel].UseItem(base);
}
int MainMenu::GetHeight() {
	return CurY;
}