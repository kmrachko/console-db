#if !defined(MY_MAIN_MENU_H)
#define MY_MAIN_MENU_H
#include "window.h"
#include <vector>
using namespace std;
class MenuItem : private Window {
private:
	string item_name;
	void(*item_action)(vector<Tovar>&);
	bool selected;
public:
	MenuItem(int, int, int, int, int, int, string, void(*)(vector<Tovar>&));
	void UseItem(vector<Tovar>&);
	void SetSelected(bool);
	int DrawBorder(int,bool&,int);
};
class MainMenu{
private:
	vector <MenuItem> items;
	int CurX, CurY;
	int menu_sel;
	int maxW;
	int align;
	bool key;
public:
	MainMenu();
	void AddMenu(string, void(*)(vector<Tovar>&));
	int GetCount();
	void Redraw(int);
	void Select(int);
	void UseMenu(vector<Tovar>&);
	int GetHeight();
};
#endif