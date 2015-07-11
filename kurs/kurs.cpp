#include <conio.h>
#include "main_menu.h"
#include "print_vec.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
void itFind(vector <Tovar>::iterator &it, Tovar a, vector <Tovar> &bd){
	it = find(bd.begin(),bd.end(),a);
}
bool compareName (Tovar a, Tovar b) {
	if (strcmp(a.Name.c_str(),b.Name.c_str())<0) return 1;
	return 0;
}
bool compareSup (Tovar a, Tovar b) {
	if (strcmp(a.Supplier.c_str(),b.Supplier.c_str())<0) return 1;
	return 0;
}
bool compareQuan (Tovar a, Tovar b) {
	if (a.Quantity>b.Quantity) return 1;
	return 0;
}
int getAlign (int msglen, int rowlen) {
	return (rowlen-msglen)/2;
}
bool isNumeric(string Str) {
	bool key=true;
	for (int i=0;i<Str.length();i++)
	{
		if(Str[i]<48||Str[i]>57)
			key=false;
	}
	return key;
}
void input(string &Str,int x, int y) {
	unsigned char ch=0;
	while (Str.length()<21)
	{
		ch=getch();
		if(!_kbhit())
		{
			if(ch==10||ch==27||ch==13) break;
			if(ch==8)
			{
				if(Str.length()>0)
				{
					Str.erase(Str.begin()+Str.length()-1);
					GotoXY(x+Str.length(),y);
					printf(" ");
					GotoXY(x+Str.length(),y);
				}
				continue;
			}
			Str+=ch;
			printf("%c",ch);
		}
		else if(_kbhit()&&(ch==0||ch==224))
		{
			getch();
			continue;
		}
	}
	return;
}
void addTovar(vector <Tovar> &a){
	string Name,Sup,Count;
	DialogWindow vvod(50,14,"Adding product");
	vvod.DrawBorder();
	int x=vvod.GetLeft();
	int y=vvod.GetTop()+1;
	GotoXY(x+2,y+4);


	SetColor(4,7);
	printf("Enter name:");
	GotoXY(x+2,y+6);
	printf("Enter supplier:");
	GotoXY(x+2,y+8);
	printf("Enter number:");
	SetColor(15,0);
	GotoXY(x+25,y+4);
	printf("                     ");
	GotoXY(x+25,y+6);
	printf("                     ");
	GotoXY(x+25,y+8);
	printf("                     ");
	GotoXY(x+25,y+4);
	//std::getline(std::cin,Name);
	input(Name,x+25,y+4);
	GotoXY(x+25,y+6);
	input(Sup,x+25,y+6);
	GotoXY(x+25,y+8);
	input(Count,x+25,y+8);
	while(!isNumeric(Count)) 
	{
		Count.clear();
		GotoXY(x+25,y+8);
		printf("                     ");
		GotoXY(x+25,y+8);
		input(Count,x+25,y+8);
	}
	Tovar temp;
	temp.Name=Name;
	temp.Quantity=atoi(Count.c_str());
	temp.Supplier=Sup;
	a.push_back(temp);
	SetConsoleOutputCP(866);
	return;
};
void delTovar(vector <Tovar> &a){
	string Name;
	DialogWindow del(50,14,"Delete product");
	del.DrawBorder();
	int x=del.GetLeft();
	int y=del.GetTop()+1;
	int al = getAlign(strlen("Enter product name to delete:"),50);
	GotoXY(x+al,y+4);

	SetColor(4,7);
	printf("Enter product name to delete:");
	al = getAlign(strlen("                     "),50);
	GotoXY(x+al,y+6);
	SetColor(15,0);
	printf("                     ");
	SetColor(7,0);
	GotoXY(x+al,y+6);
	input(Name,x+al,y+6);
	Tovar temp;
	temp.Name=Name;
	vector <Tovar>::iterator it;
	itFind(it,temp,a);
	SetColor(4,7);
	al = getAlign(strlen("Product is deleted"),50);
	GotoXY(x+al,y+8);
	printf("Product is deleted");
	a.erase(it);
	while (1)
	 if (getch()==13) break;
	SetConsoleOutputCP(866);
	return;
};
void sortTovar(vector <Tovar> &a){
	DialogWindow vvod(50,10,"Database sort");
	vvod.DrawBorder();
	int x=vvod.GetLeft();
	int y=vvod.GetTop()+1;
	int al = getAlign(strlen("Select sorting field:"),50);
	GotoXY(x+al,y+2);

	SetColor(4,7);
	printf("Select sorting field:");
	al = getAlign(strlen("Name    Supplier    Number"),50);
	GotoXY(x+al,y+5);
	printf("Name");
	printf("    ");
	printf("Supplier");
	printf("    ");
	printf("Number");
	SetConsoleOutputCP(866);
	unsigned char ch=0;
	int sor=0;
	al = getAlign(1,50);
	GotoXY(x+al,y+7);
	while (1)
	{
		ch=getch();
		if (ch==13&&sor) break;
		if ((ch-'0')<4&&(ch-'0')>0&&!sor) 
		{
			sor=ch-'0';
			printf("%d",sor);
		}
	}
	if (sor==1) sort(a.begin(),a.end(),compareName);
	if (sor==2) sort(a.begin(),a.end(),compareSup);
	if (sor==3) sort(a.begin(),a.end(),compareQuan);
	return;
};
void saveTovar(vector <Tovar> &a){
 fstream file;
 file.open("D:/database.txt",ios::out|ios::trunc);
 file.seekg(0L,ios::beg);
 for(int i = 0;i<a.size();i++)
 {
	 file << a.at(i).Name.c_str() << " " << a.at(i).Supplier.c_str() << " " << a.at(i).Quantity << endl;
 }
 file.close();
 DialogWindow vvod(50,5,"Database save");
 vvod.DrawBorder();
 int x=vvod.GetLeft();
 int y=vvod.GetTop()+1;
 GotoXY(x+19,y+2);

 SetColor(4,7);
 printf("Database is saved");
 SetConsoleOutputCP(866);
 while (1)
	 if (getch()==13) break;
}
void openTovar(vector <Tovar> &a){
  fstream file;
  file.open("D:/database.txt",ios::in); 
  file.seekg(0L,ios::end);
  a.clear();
  file.seekg(0L,ios::beg);
  while (!file.eof())
  {
     string temp, tok;
	 getline(file,temp);
	 istringstream ftok(temp);
	 Tovar buf;
	 getline(ftok,tok,' ');
	 buf.Name = tok;
	 getline(ftok,tok,' ');
	 buf.Supplier = tok;
	 getline(ftok,tok,'\n');
	 buf.Quantity = atoi(tok.c_str());
     a.push_back(buf);
  }
  a.pop_back(); 
  file.close();
  DialogWindow vvod(50,5,"Save database");
 vvod.DrawBorder();
 int x=vvod.GetLeft();
 int y=vvod.GetTop()+1;
 int al = getAlign(strlen("Database is open"),50);
 GotoXY(x+al,y+2);

 SetColor(4,7);
 printf("Database is open");
 SetConsoleOutputCP(866);
 while (1)
	 if (getch()==13) break;
}
void delallTovar(vector <Tovar> &a){
	a.clear();
	DialogWindow vvod(50,5,"Deleting products");
 vvod.DrawBorder();
 int x=vvod.GetLeft();
 int y=vvod.GetTop()+1;
 int al = getAlign(strlen("All products are deleted"),50);
 GotoXY(x+al,y+2);

 SetColor(4,7);
 printf("All products are deleted");
 SetConsoleOutputCP(866);
 while (1)
	 if (getch()==13) break;
	return;
};
int main() {
	vector <Tovar> bd;
	SetSize(90,35);
	Window * MnBorder = new Window(0,0,GetCols()-1,GetRows()-1);
	MnBorder->DrawBorder(2);
	MainMenu *a=new MainMenu();
	a->AddMenu("Open database",openTovar);
	a->AddMenu("Add product",addTovar);
	a->AddMenu("Remove product",delTovar);
	a->AddMenu("Sort products",sortTovar);
	a->AddMenu("Save database to file",saveTovar);
	a->AddMenu("Delete all products",delallTovar);
	unsigned char sel;
	int item_sel=0;
	a->Select(item_sel);
	a->Redraw(1);
	int first_rec=0;
	DrawVector p(1,GetCurrentY()+2,GetCols()-2,GetRows()-2,&bd);
	p.DrawBorder(first_rec,0);
	while(1)
	{
		sel=getch();
		if (sel==9)
		{
			a->Redraw(0);
			p.DrawBorder(first_rec,1);
			while (1)
			{
				sel=getch();
				if(sel==9) 
				{
					a->Redraw(1);
					p.DrawBorder(first_rec,0);	
					break;
				}
				if(bd.size()&&sel==224)
				{
					sel=getch();
					if(sel==72)
						if (first_rec>0)
						{
							first_rec--;
							p.DrawBorder(first_rec,1);
						}
					if(sel==80)
						if (first_rec<bd.size()-p.GetSize())
						{
							first_rec++;
							p.DrawBorder(first_rec,1);
						}
				}
			}
		}
		if(sel==13||sel==10)
		{
			a->UseMenu(bd);
			a->Redraw(1);
			p.DrawBorder(first_rec,0);
		}
		if(sel==224)
		{
			sel=getch();
			if(sel==75) 
				if(item_sel>0)
				{
					item_sel--;
					a->Select(item_sel);
					a->Redraw(1);
				}
			if(sel==77) 
				if(item_sel<a->GetCount()-1) 
				{
					item_sel++;
					a->Select(item_sel);
					a->Redraw(1);
				}
		}
	}
	return 0;
}