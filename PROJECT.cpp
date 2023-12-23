#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
using namespace std;
int x1, x;

void delay(unsigned timeout)
{
	timeout += clock();
	while (clock() < timeout)
		continue;
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void box(int h = 3, int w = 15)
{ // h=3,b=15,h=18,b=21
	char de1 = 179;
	int x = wherex();
	int y = wherey(), a = y;
	for (int i = 0; i < h; i++)
	{
		gotoxy(x, a);
		cout << de1;
		gotoxy(x + w - 1, a++);
		cout << de1;
	}
	de1 = 205;
	for (int i = 0; i < w; i++)
	{
		gotoxy(x, y);
		cout << de1;
		gotoxy(x++, y + h);
		cout << de1;
	}
}

void wave()
{
	int height = 4, length = 14, i, j, k;
	for (i = 1; i <= height; i++)
	{
		for (j = 1; j < length; j++)
		{
			for (k = 1; k <= height; k++)
			{
				if (i == k || i + k == height + 1)
					cout << "][";
				else
					cout << " ";
			}
		}
		if (i != height)
			cout << "\n";
	}
}
void xmas(int x, int y)
{
	int i, j, k, height = 2, width = 4, space = width + 2, r = 1, m = 1;
	gotoxy(x, y);
	for (r = 1; r <= height; r++)
	{
		for (i = m; i <= width; i++)
		{
			for (j = space; j >= i; j--)
			{
				cout << " ";
			}
			for (k = 1; k <= i; k++)
			{
				cout << "* ";
			}
			gotoxy(x, ++y);
		}
		m += 2;
		width += 2;
	}
	for (i = 1; i <= 4; i++)
	{
		for (j = space - 3; j >= 1; j--)
		{
			cout << " ";
		}
		for (k = 1; k <= 4; k++)
		{
			cout << "*"
				 << " ";
		}
		gotoxy(x, ++y);
	}
}
void error()
{
	system("cls");
	gotoxy(25, 9);
	cout << "AN ERROR OCCURED";
	gotoxy(25, 10);
	cout << "Press 0 to go to Back";
	gotoxy(25, 11);
	cout << "Press 1 to try again ";
}
void userinpdesign()
{ // USER INPUT DESIGN
	system("cls");
	char de = 205;
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(3, 6);
	cout << "NEW USER DET.                      MENU(M)                          CLOSE(0)";
	gotoxy(2, 5);
	box(16, 78);
	gotoxy(3, 7);
	for (int i = 0; i < 76; i++)
		cout << de;
	gotoxy(4, 8);
	box(3, 35);
	gotoxy(4, 12);
	box(3, 35);
	gotoxy(4, 16);
	box(3, 35);
	gotoxy(43, 8);
	box(3, 35);
	gotoxy(43, 12);
	box(3, 35);
	gotoxy(43, 16);
	box(3, 35);
}
void adminlogin()
{
	system("cls");
	int x = 22; // admin login window
	gotoxy(6, 4);
	cout << "ADMIN LOGIN WINDOW";
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(x - 2, 7);
	cout << "_____";
	gotoxy(x - 1, 8);
	cout << "___";
	gotoxy(x - 1, 17);
	cout << "___";
	gotoxy(x - 2, 18);
	cout << "_____";
	for (int i = 0; i < 35; i++)
	{
		gotoxy(x, 7);
		cout << "_";
		gotoxy(x, 8);
		cout << "_";
		gotoxy(x, 10);
		cout << "*";
		gotoxy(x, 16);
		cout << "*";
		gotoxy(x, 17);
		cout << "_";
		gotoxy(x, 18);
		cout << "_";
		x++;
	}
	gotoxy(x, 7);
	cout << "____";
	gotoxy(x, 8);
	cout << "__";
	gotoxy(x, 17);
	cout << "__";
	gotoxy(x, 18);
	cout << "____";
	gotoxy(23, 11);
	cout << "Press Enter key when finished";
	gotoxy(25, 13);
	cout << "username : ";
	::x = wherex();
	gotoxy(25, 14);
	cout << "password : ";
	::x1 = wherex();
}
void tolldesign()
{ // TOLL DESIGN
	system("cls");
	char de = 205;
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(3, 6);
	cout << "TOLL DATA INPUT                    MENU(M)                          CLOSE(0)";
	gotoxy(2, 5);
	box(16, 78);
	gotoxy(3, 7);
	for (int i = 0; i < 76; i++)
		cout << de;
	gotoxy(4, 8);
	box(3, 35);
	gotoxy(4, 12);
	box(3, 35);
	gotoxy(43, 8);
	box(3, 35);
	gotoxy(43, 12);
	box(3, 35);
	gotoxy(4, 16);
	box(4, 74);
}

class toll
{ // TOLL CLASS
public:
	int id;
	char name[20], email[30], contact[12], username[15], password[15];
	void getdata();
	void showdata();
};
void toll::getdata()
{
	char c;
	tolldesign();
	gotoxy(4, 8);
	cout << "Enter ID";
	gotoxy(5, 9);
	cin >> id;
	gotoxy(4, 12);
	cout << "Enter Name";
	gotoxy(5, 13);fflush(stdin);
	gets(name);
	gotoxy(43, 8);
	cout << "Enter Email";
	gotoxy(44, 9);fflush(stdin);
	gets(email);
	gotoxy(43, 12);
	cout << "Enter contact";
	gotoxy(44, 13);fflush(stdin);
	gets(contact);
	gotoxy(20, 17);
	cout << "Enter username : ";
	gets(username);fflush(stdin);
	gotoxy(20, 18);
	cout << "Enter password : ";
	for (int i = 0;; i++)
	{
		c = getch();
		if (c == '\r')
		{
			password[i] = '\0';
			break;
		}
		if (c == '\b')
		{
			int x, y;
			x = wherex();
			y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			i -= 2;
		}
		else
		{
			password[i] = c;
			cout << "*";
		}
	}
}
void toll::showdata()
{
	tolldesign();
	gotoxy(4, 8);
	cout << "ID";
	gotoxy(5, 9);
	cout << id;
	gotoxy(4, 12);
	cout << "Name";
	gotoxy(5, 13);
	puts(name);
	gotoxy(43, 8);
	cout << "Email";
	gotoxy(44, 9);
	puts(email);
	gotoxy(43, 12);
	cout << "Contact";
	gotoxy(44, 13);
	puts(contact);
}
class customer
{ // CUSTOMER CLASS
public:
	int id, price_veh;
	char name[50], address[50], phone[12], email[80], card_num[12];
	double price_card, veh_amt;
	char username[30], password[30], c;
	char veh_type[10], veh_no[17];
	fstream ifs;
	customer(){
		id = 0;
		veh_amt = 0;
		price_card = 0;
		price_veh = 0;
		strcpy(card_num,"default");
	}
	void addprice()
	{
		double add;
		cout << "Enter Amount to be added : ";
		cin >> add;
		price_card = price_card + add;
	}
	void veh_price()
	{
		if (strcmpi("car", veh_type) == 0)
		{
			price_card = price_card - 50;
			veh_amt = 50;
		}
		if (strcmpi("truck", veh_type) == 0)
		{
			price_card = price_card - 80;
			veh_amt = 80;
		}
		if (strcmpi("Bike", veh_type) == 0)
		{
			price_card = price_card - 30;
			veh_amt = 30;
		}
		if (strcmpi("cycle", veh_type) == 0)
		{
			price_card = price_card - 10;
			veh_amt = 10;
		}
		else
		{
			price_card = price_card - 25;
			veh_amt = 25;
		}
	}
	void getdata();
	void showdata();
};

void customer ::showdata()
{
	userinpdesign();
	gotoxy(4, 8);
	cout << "ID";
	gotoxy(5, 9);
	cout << id;
	gotoxy(4, 12);
	cout << "Name";
	gotoxy(5, 13);
	puts(name);
	gotoxy(4, 16);
	cout << "Contact Number";
	gotoxy(5, 17);
	puts(phone);
	gotoxy(43, 8);
	cout << "Username";
	gotoxy(44, 9);
	puts(username);
	gotoxy(43, 12);
	cout << "Vehicle name";
	gotoxy(44, 13);
	puts(veh_type);
	gotoxy(43, 16);
	cout << "E-mail ID";
	gotoxy(44, 17);
	puts(email);
}

void customer ::getdata()
{
	userinpdesign();
	gotoxy(4, 8);
	cout << "Enter your name : ";
	gotoxy(5, 9);
	gets(name);
	gotoxy(4, 12);
	cout << "Enter the address : ";
	gotoxy(5, 13);
	gets(address);
	gotoxy(4, 16);
	cout << "Enter phone number : ";
	gotoxy(5, 17);
	gets(phone);
	gotoxy(43, 8);
	cout << "Enter type of vehicle : ";
	gotoxy(44, 9);
	gets(veh_type);
	gotoxy(43, 12);
	cout << "Enter E-mail address : ";
	gotoxy(44, 13);
	gets(email);
	gotoxy(43, 16);
	cout << "Enter vehicle number";
	gotoxy(44, 17);
	gets(veh_no);
	getch();
	system("cls");
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(23, 11);
	cout << "Press Enter key when finished";
	gotoxy(25, 13);
	cout << "username : ";
	::x = wherex();
	gotoxy(25, 14);
	cout << "password : ";
	::x1 = wherex();
eu:
	gotoxy(::x, 13);
	gets(username);
	gotoxy(::x1, 14);
	for (int i = 0;; i++)
	{
		c = getch();
		if (c == '\r')
		{
			password[i] = '\0';
			break;
		}
		if (c == '\b')
		{
			int x, y;
			x = wherex();
			y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			i -= 2;
		}
		else
		{
			password[i] = c;
			cout << "*";
		}
	}
}
class admin
{
public:
	char username[14];
	customer cus;
	char password[14];
	void decide();
};

int main()
{ // MAIN FUNCTION
	system("cls");
	char cg;int fg=0;
	ifstream iffs;
	iffs.open("hs.txt");
	while (!kbhit()&&!iffs.eof())
	{
		iffs.get(cg);
		if (cg == '\n'){
            fg=1;
			delay(300);
		}
		cout << cg;
	}
	iffs.close();cout<<endl<<endl;
	cout << "Press any key";
	getch();
	system("cls");
	gotoxy(15, 7);
	cout << "Press 1 to see intro";
	gotoxy(15, 8);
	cout << "Press any other key to skip intro";
	char h = getch();
	if (h != '1')
		goto start;
	if (h == '1')
	{
		system("cls");
		ifstream ifs;
		int i;
		char c;
		ifs.open("intro.txt");
		while (!ifs.eof())
		{
			ifs.get(c);
			if (c == '\t')
				goto ag;
			delay(30);
		ag:
			cout << c;
		}
		ifs.close();
		cout << "\nPress any key ";
		getch();
	}
start:
	int x3, x4;
	int x2 = x;
	customer cus;
	toll tol;
	char uflname[15];
	char uname[15], uword[15];
	int flag = 0;
	ifstream ifs;
	long x, y, x1;
	int i;
	x = 22;
	admin adm;
	char c, de1 = 179, adname[30], adpass[30];
	x2 = x;
	x = 22;
	gotoxy(x2, 8);
	system("cls");
	strcpy(adm.username, "admintoll223");
	strcpy(adm.password, "welcomeadmin");
	xmas(1, 7);
	xmas(68, 7);
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(x - 3, 7);
	cout << "_____";
	gotoxy(x - 2, 8);
	cout << "___";
	gotoxy(x - 2, 18);
	cout << "___";
	gotoxy(x - 3, 19);
	cout << "_____";
	y = 7;
	for (i = 0; i < 35; i++)
	{
		gotoxy(x - 1, 7);
		cout << "_";
		gotoxy(x - 1, 8);
		cout << "_";
		gotoxy(x - 1, 10);
		cout << "*";
		gotoxy(x - 1, 17);
		cout << "*";
		gotoxy(x - 1, 18);
		cout << "_";
		gotoxy(x - 1, 19);
		cout << "_";
		x++;
	}
	gotoxy(x - 2, 7);
	cout << "____";
	gotoxy(x - 2, 8);
	cout << "__";
	gotoxy(x - 2, 18);
	cout << "__";
	gotoxy(x - 2, 19);
	cout << "____";
	gotoxy(22, 12);
	cout << "Press 1 if you are admin";
	gotoxy(22, 13);
	cout << "Press 2 if you are user";
	gotoxy(22, 14);
	cout << "Press 3 if you are plaza master";
	gotoxy(22, 15);
	cout << "Press 0 if you want to exit";
	char d;
	d = getch();
	if (d != '0' && d != '1' && d != '2' && d != '3')
	{
		gotoxy(23, 19);
		cout << "INVALID CHOICE\tpress any key";
		getch();
		goto start;
	}
	if (d == '3')
	{
		system("cls");
		adminlogin();
		goto tollmaster;
	}
	if (d == '0')
	{
		exit(0);
	}
	if (d == '1')
	{
		adminlogin();
		goto adminname;
	}
	if (d == '2')
	{
		system("cls");
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(13, 9);
		box(4, 45);
		gotoxy(14, 11);
		cout << "Press 1 if you are existing customer";
		gotoxy(13, 15);
		box(4, 45);
		gotoxy(14, 17);
		cout << "Press 2 if you are new user";
		d = getch();
		if (d == '1')
		{
			adminlogin();
			gotoxy(6, 4);
			cout << "USER LOGIN WINDOW";
			goto username;
		}
		if (d == '2')
		{
			system("cls");
			ofstream ofs;
			cus.getdata();
			ofs.open("requestedCustomers.dat", ios::binary | ios::app);
			ofs.write((char *)&cus, sizeof(cus));
			ofs.close();
			cout << "Data successful\npress any key to continue";
			getch();
			goto start;
		}
		if (d != '1' && d != '2')
		{
			system("cls");
			cout << "INVALID CHOICE PRESS ANY KEY";
			getch();
			goto start;
		}
	}
adminname:
	gotoxy(::x, 13);
	cout << "                                ";
	gotoxy(::x, 13);
	for (i = 0;; i++)
	{ // CODE FOR ADMINNAME
		c = getch();
		if (c == '\r')
		{
			adname[i] = '\0';
			if (strcmp(adname, adm.username) == 0)
			{
				gotoxy(55, 13);
				cout << "matched";
				break;
			}
			else
			{
				gotoxy(x + 20, 13);
				cout << "not matched";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				system("cls");
				gotoxy(25, 9);
				cout << "AN ERROR OCCURED";
				gotoxy(25, 10);
				cout << "Press 0 to go to Back";
				gotoxy(25, 11);
				cout << "Press 1 to try again ";
			jj:
				d = getch();
				if (d != '1' && d != '0')
				{
					gotoxy(15, 12);
					cout << "INVALID CHOICE CHOOSE AGAIN";
					goto jj;
				}
				if (d == '0')
					goto start;
				if (d == '1')
					adminlogin();
				goto adminname;
			}
		}
		if (c == '\b')
		{
			int x, y;
			x = wherex();
			y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			i -= 2;
		}
		else
		{
			adname[i] = c;
			cout << c;
		}
	}
adminpassword:
	gotoxy(::x1, 14);
	de1 = 179;
	for (i = 0;; i++)
	{ // CODE FOR PASSWORD
		c = getch();
		if (c == '\r')
		{
			adpass[i] = '\0';
			if (strcmp(adpass, adm.password) == 0)
			{
				gotoxy(55, 14);
				cout << "matched";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				goto adminhome;
			}
			else
			{
				gotoxy(::x + 20, 14);
				cout << "not matched";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				system("cls");
				gotoxy(25, 9);
				cout << "AN ERROR OCCURED";
				gotoxy(25, 10);
				cout << "Press 0 to go to Back";
				gotoxy(25, 11);
				cout << "Press 1 to try again ";
			q:
				d = getch();
				if (d != '0' && d != '1')
				{
					gotoxy(15, 12);
					cout << "INCVALID CHOICE CHOOSE AGAIN";
					goto q;
				}
				if (d == '0')
					goto start;
				if (d == '1')
					adminlogin();
				gotoxy(::x, 13);
				cout << "admintoll223";
				gotoxy(55, 13);
				cout << "matched";
				goto adminpassword;
			}
		}
		if (c == '\b')
		{
			int x, y;
			x = wherex();
			y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			i -= 2;
		}
		else
		{
			adpass[i] = c;
			cout << de1;
		}
	}
adminhome:
	system("cls");
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(10, 6);
	cout << "ADMIN HOME SCREEN\t\tMENU(M)\t\t\tCLOSE(0)";
	de1 = 205;
	gotoxy(10, 7);
	for (i = 0; i < 64; i++)
		cout << de1;
	gotoxy(9, 5);
	box(16, 65);
	gotoxy(13, 9);
	box(4, 27);
	gotoxy(14, 11);
	cout << "1)For user registration";
	gotoxy(43, 9);
	box(4, 27);
	gotoxy(44, 11);
	cout << "2)To view registered user";
	gotoxy(13, 15);
	box(4, 27);
	gotoxy(14, 17);
	cout << "3)To recharge smart card";
	gotoxy(43, 15);
	box(4, 27);
	gotoxy(44, 17);
	cout << "4)For Toll Plaza Master";
	de1 = getch();
	if (de1 == '0')
		exit(0);
	if (de1 == 'm' || de1 == 'M')
		goto start;
	if (de1 != '1' && de1 != '2' && de1 != '3' && de1 != '4' && de1 != '0' && de1 != 'm' && de1 != 'M')
	{
		error();
		int u = wherex(), v = wherey();
		char d;
	vv:
		d = getch();
		if (d == '0')
			goto start;
		if (d == '1')
			goto adminhome;
		if (d != '0' && d != '1')
		{
			gotoxy(u, v + 1);
			cout << "Invalid choice choose again";
			goto vv;
		}
	}

	if (de1 == '4')
	{
	uptol:
		ofstream ofs;
		system("cls");
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(10, 6);
		cout << "ADMIN SCREEN     \t\tMENU(M)\t\t\tCLOSE(0)";
		de1 = 205;
		gotoxy(10, 7);
		for (i = 0; i < 64; i++)
			cout << de1;
		gotoxy(9, 5);
		box(16, 65);
		gotoxy(13, 9);
		box(4, 27);
		gotoxy(14, 11);
		cout << "1)View Tolls";
		gotoxy(43, 9);
		box(4, 27);
		gotoxy(44, 11);
		cout << "2)Create New Toll";
		gotoxy(13, 15);
		box(4, 27);
		gotoxy(14, 17);
		cout << "3)Delete Existing";
		gotoxy(43, 15);
		box(4, 27);
		gotoxy(44, 17);
		cout << "4)Update Toll";
		char bb = getch();
		if (bb == 'M' || bb == 'm')
			goto start;
		if (bb == '0')
			exit(0);
		if (bb != '1' && bb != '2' && bb != '3' && bb != '4')
		{
			error();
			char d;
		gl:
			d = getch();
			if (d == '1')
				goto uptol;
			if (d == '0')
				goto start;
			if (d != '1' && d != '0')
			{
				cout << "\n\n\t\t\tINVALID CHOICE CHOOSE AGAIN";
				goto gl;
			}
		}
	toldelete:
		if (bb == '4')
		{
			system("cls");
			x2 = x;
			x = 22;
			int flag = 0;
			gotoxy(1, 1);
			wave();
			gotoxy(1, 22);
			wave();
			gotoxy(x - 3, 6);
			cout << "_____";
			gotoxy(x - 2, 7);
			cout << "___";
			gotoxy(x - 2, 17);
			cout << "___";
			gotoxy(x - 3, 18);
			cout << "_____";
			y = 7;
			for (i = 0; i < 35; i++)
			{
				gotoxy(x - 1, 6);
				cout << "_";
				gotoxy(x - 1, 7);
				cout << "_";
				gotoxy(x - 1, 9);
				cout << "*";
				gotoxy(x - 1, 16);
				cout << "*";
				gotoxy(x - 1, 17);
				cout << "_";
				gotoxy(x - 1, 18);
				cout << "_";
				x++;
			}
			gotoxy(x - 2, 6);
			cout << "____";
			gotoxy(x - 2, 7);
			cout << "__";
			gotoxy(x - 2, 17);
			cout << "__";
			gotoxy(x - 2, 18);
			cout << "____";
			gotoxy(22, 12);
			cout << "Press 1 to update by ID";
			gotoxy(22, 13);
			cout << "Press M to go to menu";
			gotoxy(22, 14);
			cout << "Press 0 to exit";
			char d = getch();
			fstream fs;
			if (d == '0')
				exit(0);
			if (d == 'm' || d == 'M')
				goto start;
			if (d != '1')
			{
				error();
				char o;
			oo:
				o = getch();
				if (o != '1' && o != '0')
				{
					cout << "\n\n\t\t\tINVALID CHOICE CHOOSE AGAIN";
					goto oo;
				}
				if (o == '1')
					goto toldelete;
				if (o == '0')
					goto start;
			}
			if (d == '1')
			{
				int ide;
				long t;
				gotoxy(22, 12);
				cout << "Enter the ID to update : ";
				cin >> ide;
				fs.open("tol.dat", ios::binary | ios::in | ios::out);
				while (!ifs.eof())
				{
					t = fs.tellg();
					fs.read((char *)&tol, sizeof(tol));
					if (fs.eof())
						break;
					if (tol.id == ide)
					{
						flag = 1;
						tol.getdata();
						fs.seekg(t);
						fs.write((char *)&tol, sizeof(tol));
						gotoxy(23, 12);
						cout << " Job Done Successfully";
						gotoxy(25, 13);
						cout << "Press Any Key";
						getch();
						goto adminhome;
					}
				}
				fs.close();
				if (flag == 0)
				{
					error();
					char d;
				ee:
					d = getch();
					if (d == '1')
						goto uptol;
					if (d == '0')
						goto start;
					if (d != '1' && d != '0')
					{
						cout << "\n\n\t\t\tINVALID CHOICE CHOOSE AGAIN";
						goto ee;
					}
				}
			}
		}
		if (bb == '3')
		{
			system("cls");
			x2 = x;
			x = 22;
			int flag = 0;
			gotoxy(1, 1);
			wave();
			gotoxy(1, 22);
			wave();
			gotoxy(x - 3, 6);
			cout << "_____";
			gotoxy(x - 2, 7);
			cout << "___";
			gotoxy(x - 2, 17);
			cout << "___";
			gotoxy(x - 3, 18);
			cout << "_____";
			y = 7;
			for (i = 0; i < 35; i++)
			{
				gotoxy(x - 1, 6);
				cout << "_";
				gotoxy(x - 1, 7);
				cout << "_";
				gotoxy(x - 1, 9);
				cout << "*";
				gotoxy(x - 1, 16);
				cout << "*";
				gotoxy(x - 1, 17);
				cout << "_";
				gotoxy(x - 1, 18);
				cout << "_";
				x++;
			}
			gotoxy(x - 2, 6);
			cout << "____";
			gotoxy(x - 2, 7);
			cout << "__";
			gotoxy(x - 2, 17);
			cout << "__";
			gotoxy(x - 2, 18);
			cout << "____";
			gotoxy(22, 12);
			cout << "Press 1 to delete by ID";
			gotoxy(22, 13);
			cout << "Press M to go to menu";
			gotoxy(22, 14);
			cout << "Press 0 to exit";
			remove("temp.dat");
			ifstream ifs;
			toll tol;
			ofstream ofs;
			char p;
			p = getch();
			if (p == 'M' || p == 'm')
				goto start;
			if (p == '0')
				exit(0);
			if (p == '1')
			{
				int ide;
				gotoxy(22, 12);
				cout << "Enter the ID to delete : ";
				cin >> ide;
				ifs.open("toll.dat", ios::binary);
				while (!ifs.eof())
				{
					ifs.read((char *)&tol, sizeof(tol));
					if (ifs.eof())
						break;
					ofs.open("temp.dat", ios::binary | ios::app);
					if (ide == tol.id)
					{
						flag = 1;
						goto lst;
					}
					ofs.write((char *)&tol, sizeof(tol));
				lst:
					ofs.close();
				}
				ifs.close();
				if (flag == 1)
				{
					system("cls");
					remove("toll.dat");
					rename("temp.dat", "toll.dat");
					gotoxy(23, 12);
					cout << " Job Done Successfully";
					gotoxy(25, 13);
					cout << "Press Any Key";
					getch();
					goto adminhome;
				}
				if (flag == 0)
				{
					error();
					char g;
					g = getch();
					if (g == '0')
						goto adminhome;
					if (g == '1')
						goto toldelete;
				}
				goto adminhome;
			}
		}
		if (bb == '2')
		{
			tol.getdata();
			ofs.open("toll.dat", ios::binary | ios::app);
			ofs.write((char *)&tol, sizeof(tol));
			ofs.close();
			getch();
			goto adminhome;
		}
		if (bb == '1')
		{
			i = 1;
			ifstream ifs;
			ifs.open("tol.dat", ios::binary);
			while (!ifs.eof())
			{
				ifs.read((char *)&tol, sizeof(tol));
				if (ifs.eof())
					break;
				tol.showdata();
				y = wherey();
				gotoxy(3, y + 4);
				cout << " PREVIOUS(P)                                                        NEXT(N)\n";
				char dee = getch();
				if (dee == 'M' || dee == 'm')
					goto start;
				if (dee == '0')
					exit(0);
				if (dee == 'P' || dee == 'p')
				{
					ifs.seekg((i) * sizeof(tol));
					i -= 1;
				}
				i++;
			}
			ifs.close();
			system("cls");
			gotoxy(25, 10);
			cout << "JOB DONE SUCCESSFULLY...";
			gotoxy(25, 11);
			cout << "PRESS ANY KEY ";
			getch();
			goto adminhome;
		}
	}
	if (de1 == '3')
	{
		userinpdesign();
		int id, flag = 0;
		float iprice;
		gotoxy(3, 6);
		cout << "ENTER THE ID TO RECAHARGE SMART CARD :                                        ";
		gotoxy(44, 6);
		cin >> id;
		fstream ifs;
		long t;
		char flname[15];
		ifs.open("permanentCustomers.dat", ios::binary | ios::in | ios::out);
		while (!ifs.eof())
		{
			t = ifs.tellg();
			ifs.read((char *)&cus, sizeof(cus));
			if (ifs.eof())
				break;
			if (cus.id == id)
			{
				strcpy(flname, cus.username);
				strcat(flname, ".txt");
				gotoxy(3, 6);
				cout << "ENTER THE ID TO RECAHARGE SMART CARD :                                        ";
				gotoxy(44, 6);
				cout << id;
				cus.showdata();
				flag = 1;
				gotoxy(5, 20);
				cout << " ENTER THE RECHARGING AMOUNT :                                                ";
				gotoxy(38, 20);
				cin >> iprice;
				ofstream off;
				off.open(flname, ios::app);
				off << "\nAMOUNT RECHARGED : " << iprice;
				off.close();
				cus.price_card = cus.price_card + iprice;
				gotoxy(5, 20);
				cout << " PRESS ANY KEY                                                               ";
				getch();
				ifs.seekg(t);
				ifs.write((char *)&cus, sizeof(cus));
				goto adminhome;
			}
		}
		if (flag == 0)
		{
			y = wherey();
			gotoxy(5, 20);
			cout << " NOT FOUND PREASS ANY KEY                                                    ";
			getch();
			goto adminhome;
		}
	}
	if (de1 == '2')
	{
		int i = 1;
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(3, 6);
		cout << "USER DETAILS ";
		ifstream ifs;
		long t;
		char dee;
		ifs.open("permanentCustomers.dat", ios::binary);
		while (!ifs.eof())
		{
			ifs.read((char *)&cus, sizeof(cus));
			if (ifs.eof())
				break;
			if (cus.id == -1)
				goto alast;
			cus.showdata();
			y = wherey();
			gotoxy(3, y + 2);
			cout << " PREVIOUS(P)                                                        NEXT(N)\n";
			dee = getch();
			if (dee == 'M' || dee == 'm')
				goto start;
			if (dee == '0')
				exit(0);
			if (dee == 'P' || dee == 'p')
			{
				ifs.seekg((i - 1) * sizeof(cus));
				i -= 2;
			}
			i++;
		alast:
			cout << "hi";
			system("cls");
		}
		ifs.close();
		system("cls");
		gotoxy(25, 10);
		cout << "JOB DONE SUCCESSFULLY...";
		gotoxy(25, 11);
		cout << "PRESS ANY KEY ";
		getch();
		goto adminhome;
	}
	if (de1 == '1')
	{
		system("cls");
		customer cus;
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(3, 6);
		cout << "USER DETAILS ";
		ifstream ifsq;
		char d;
		long t;
		ifsq.open("requestedCustomers.dat", ios::binary);
		int y;
		int i = 1;
		char flname[15];
		while (!ifsq.eof())
		{
			ifsq.read((char *)&cus, sizeof(cus));
			if (ifsq.eof())
				break;
			if (cus.id == -1)
				goto lastdat;
			i = 1;
			cout << "Details of customer " << i << ":\n\n";
			cus.showdata();
			y = wherey();
			gotoxy(3, y + 2);
			cout << " Accept(A)                        Reject(R)                         Skip(S)\n";
			d = getch();
			if (d == '0')
				exit(0);

			if (d == 'a' || d == 'A')
			{
				strcpy(flname, cus.username);
				strcat(flname, ".txt");
				system("cls");
				ofstream ofs;
				gotoxy(1, 1);
				wave();
				gotoxy(1, 22);
				wave();
				char de = 205;
				gotoxy(1, 1);
				wave();
				gotoxy(1, 22);
				wave();
				gotoxy(18, 7);
				box(10, 50);
				gotoxy(19, 8);
				for (int i = 0; i < 48; i++)
					cout << de;
				gotoxy(19, 10);
				for (i = 0; i < 48; i++)
					cout << de;
				gotoxy(19, 11);
				for (i = 0; i < 48; i++)
					cout << de;
				gotoxy(19, 13);
				for (i = 0; i < 48; i++)
					cout << de;
				gotoxy(19, 14);
				for (i = 0; i < 48; i++)
					cout << de;
				gotoxy(19, 16);
				for (i = 0; i < 48; i++)
					cout << de;
				gotoxy(22, 9);
				cout << "Enter ID : ";
				cin >> cus.id;
				gotoxy(22, 12);
				cout << "Enter card number : ";
				fflush(stdin);
				gets(cus.card_num);
				gotoxy(22, 15);
				cout << "Enter amount in the card : ";
				cin >> cus.price_card;
				ofstream off;
				off.open(flname, ios::app);
				off << "\nAMOUNT RECHARGED : " << cus.price_card;
				off.close();
				ofs.open("permanentCustomers.dat", ios::binary | ios::app);
				ofs.write((char *)&cus, sizeof(cus));
				ofs.close();
				remove("temp.dat");
				ifstream is;
				ofstream os;
				customer cusi;
				is.open("requestedCustomers.dat", ios::binary);
				while (!is.eof())
				{
					is.read((char *)&cusi, sizeof(cusi));
					if (is.eof())
						break;
					if (cus.id == cusi.id)
						continue;
					os.open("temp.dat", ios::binary | ios::app);
					os.write((char *)&cusi, sizeof(cusi));
					os.close();
				}
				is.close();
				remove("requestedCustomers.dat");
				rename("temp.dat", "requestedCustomers.dat");
			}
			if (d == 'r' || d == 'R')
			{
				remove("temp.dat");
				ifstream is;
				ofstream os;
				customer cusi;
				is.open("requestedCustomers.dat", ios::binary);
				while (!is.eof())
				{
					is.read((char *)&cusi, sizeof(cusi));
					if (is.eof())
						break;
					if (cus.id == cusi.id)
						continue;
					os.open("temp.dat", ios::binary | ios::app);
					os.write((char *)&cusi, sizeof(cusi));
					os.close();
				}
				is.close();
				remove("requestedCustomers.dat");
				rename("temp.dat", "requestedCustomers.dat");
			}
		lastdat:
			cout << "hi";
			system("cls");
		}
		ifsq.close();
		system("cls");
		gotoxy(25, 10);
		cout << "JOB DONE SUCCESSFULLY...";
		gotoxy(25, 11);
		cout << "PRESS ANY KEY ";
		getch();
		goto start;
	}
username:
	x = 22;
	flag = 0;
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(x - 2, 7);
	cout << "_____";
	gotoxy(x - 1, 8);
	cout << "___";
	gotoxy(x - 1, 17);
	cout << "___";
	gotoxy(x - 2, 18);
	cout << "_____";
	for (i = 0; i < 35; i++)
	{
		gotoxy(x, 7);
		cout << "_";
		gotoxy(x, 8);
		cout << "_";
		gotoxy(x, 10);
		cout << "*";
		gotoxy(x, 16);
		cout << "*";
		gotoxy(x, 17);
		cout << "_";
		gotoxy(x, 18);
		cout << "_";
		x++;
	}
	gotoxy(x, 7);
	cout << "____";
	gotoxy(x, 8);
	cout << "__";
	gotoxy(x, 17);
	cout << "__";
	gotoxy(x, 18);
	cout << "____";
	gotoxy(23, 11);
	cout << "Press Enter key when finished";
	gotoxy(25, 13);
	cout << "Enter username : ";
	x3 = wherex();
	gotoxy(25, 14);
	cout << "Enter password : ";
	x4 = wherex();
	gotoxy(x3, 13);
	gets(uname);
	ifs.open("permanentCustomers.dat", ios::binary);
	while (!ifs.eof())
	{
		ifs.read((char *)&cus, sizeof(cus));
		if (ifs.eof())
			break;
		if (strcmp(cus.username, uname) == 0)
		{
			flag = 1;
			gotoxy(55, 13);
			cout << "matched                ";
			gotoxy(23, 19);
		upword:
			gotoxy(x4, 14);
			cout << "                                    ";
			gotoxy(x4, 14);
			for (int i = 0;; i++)
			{
				c = getch();
				if (c == '\r')
				{
					uword[i] = '\0';
					break;
				}
				if (c == '\b')
				{
					int x, y;
					x = wherex();
					y = wherey();
					gotoxy(x - 1, y);
					cout << " ";
					gotoxy(x - 1, y);
					i -= 2;
				}
				else
				{
					uword[i] = c;
					cout << "*";
				}
			}
			if (strcmp(uword, cus.password) == 0)
			{
				gotoxy(55, 14);
				cout << "matched                ";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				strcpy(uflname, cus.username);
				strcat(uflname, ".txt");
				goto userhome;
			}
			else
			{
				gotoxy(55, 14);
				cout << "not matched";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				system("cls");
				gotoxy(25, 9);
				cout << "AN ERROR OCCURED";
				gotoxy(25, 10);
				cout << "Press 0 to go to Back";
				gotoxy(25, 11);
				cout << "Press 1 to try again ";
				d = getch();
				if (d == '0')
					goto start;
				if (d == '1')
					goto upword;
			}
		}
	}
	ifs.close();
	if (flag == 0)
	{
		gotoxy(55, 13);
		cout << "not matched";
		gotoxy(23, 19);
		cout << "Press any key";
		getch();
		system("cls");
		gotoxy(25, 9);
		cout << "AN ERROR OCCURED";
		gotoxy(25, 10);
		cout << "Press 0 to go to Back";
		gotoxy(25, 11);
		cout << "Press 1 to try again ";
		d = getch();
		if (d == '0')
			goto start;
		if (d == '1')
			goto username;
	}
userhome:
	system("cls");
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(10, 6);
	cout << "USER HOME SCREEN\t\tMENU(M)\t\t\tCLOSE(0)";
	de1 = 205;
	gotoxy(10, 7);
	for (i = 0; i < 64; i++)
		cout << de1;
	gotoxy(9, 5);
	box(16, 65);
	gotoxy(13, 9);
	box(4, 27);
	gotoxy(14, 11);
	cout << "1)View Card History";
	gotoxy(43, 15);
	box(4, 27);
	gotoxy(44, 17);
	cout << "2)View Toll Plaza entries";
	de1 = getch();
	if (de1 == '0')
		exit(0);
	if (de1 == 'm' || de1 == 'M')
		goto start;
	if (de1 == '2')
	{
		system("cls");
		int y = 7, co = 0;
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(3, 6);
		cout << "PASSED HISTORY                     MENU(M)                          CLOSE(0)";
		gotoxy(3, 7);
		char de = 205;
		for (int i = 0; i < 76; i++)
			cout << de;
		gotoxy(2, 5);
		box(16, 78);
		gotoxy(3, 8);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 10);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 12);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 14);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 16);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 18);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 20);
		for (i = 0; i < 76; i++)
			cout << de;
		y = 7;
		ifstream ifs;
		char c, str[30], tfname[20];
		strcpy(tfname, uname);
		strcat(tfname, ".txt");
		ifs.open(tfname);
		while (!ifs.eof())
		{
			ifs.get(c);
			cout << c;
			if (c == '\n')
			{
				gotoxy(4, y += 2);
				cout << "                                                      ";
				gotoxy(4, y);
				co++;
			}
			if (co > 6)
			{
				co = 0;
				y = 7;
			}
		}
		ifs.close();
		gotoxy(4, 21);
		cout << "Press any key                          ";
		getch();
		goto userhome;
	}
	if (de1 == '1')
	{
		system("cls");
		int y = 7, co = 0;
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(3, 6);
		cout << "CARD HISTORY                       MENU(M)                          CLOSE(0)";
		gotoxy(3, 7);
		char de = 205;
		for (int i = 0; i < 76; i++)
			cout << de;
		gotoxy(2, 5);
		box(16, 78);
		gotoxy(3, 8);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 10);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 12);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 14);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 16);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 18);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 20);
		for (i = 0; i < 76; i++)
			cout << de;
		y = 7;
		ifstream ifs;
		char c, str[30];
		ifs.open(uflname);
		while (!ifs.eof())
		{
			ifs.get(c);
			cout << c;
			if (c == '\n')
			{
				gotoxy(4, y += 2);
				co++;
			}
			if (co > 6)
			{
				co = 0;
				y = 7;
			}
		}
		ifs.close();
		gotoxy(4, 21);
		cout << "Press any key";
		getch();
		goto userhome;
	}
tollmaster:
	char tword[20], tname[20];
	flag = 0;
	adminlogin();
	gotoxy(6, 6);
	cout << "TOLL LOGIN WINDOW";
	gotoxy(::x, 13);
	gets(tname);
	ifs.open("toll.dat", ios::binary);
	while (!ifs.eof())
	{
		ifs.read((char *)&tol, sizeof(tol));
		if (ifs.eof())
			break;
		if (strcmp(tol.username, tname) == 0)
		{
			flag = 1;
			gotoxy(55, 13);
			cout << "matched";
			goto tolpass;
		}
	}
	ifs.close();
	if (flag == 0)
	{
		error();
		char d = getch();
		if (d == '1')
			goto tollmaster;
		if (d == '0')
			goto start;
	}
tolpass:
	gotoxy(::x1, 14);
	for (i = 0;; i++)
	{
		c = getch();
		if (c == '\r')
		{
			tword[i] = '\0';
			break;
		}
		if (c == '\b')
		{
			int x, y;
			x = wherex();
			y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			i -= 2;
		}
		else
		{
			tword[i] = c;
			cout << "*";
		}
	}
	flag = 0;
	ifs.open("tol.dat", ios::binary);
	while (!ifs.eof())
	{
		ifs.read((char *)&tol, sizeof(tol));
		if (ifs.eof())
			break;
		if (strcmp(tol.username, tname) == 0 && strcmp(tol.password, tword) == 0)
		{
			flag = 1;
			gotoxy(55, 14);
			cout << "matched";
			gotoxy(23, 19);
			cout << "Press any key";
			getch();
			goto tolhome;
		}
	}
	ifs.close();
	if (flag == 0)
	{
		gotoxy(55, 13);
		cout << "not matched";
		gotoxy(23, 19);
		cout << "Press any key";
		getch();
	l:
		error();
		d = getch();
		if (d == '1')
		{
			adminlogin();
			gotoxy(6, 6);
			cout << "TOLL LOGIN WINDOW";
			gotoxy(::x, 13);
			puts(tname);
			goto tolpass;
		}
		if (d == '0')
		{
			goto start;
		}
		else
		{
			cout << "\n\n\t\tINVALID CHOICE";
			cout << "\nPRESS ANY KEY";
			getch();
			goto l;
		}
	}
tolhome:
	system("cls");
	gotoxy(1, 1);
	wave();
	gotoxy(1, 22);
	wave();
	gotoxy(10, 6);
	cout << "TOLL HOME SCREEN \t\tMENU(M)\t\t\tCLOSE(0)";
	de1 = 205;
	gotoxy(10, 7);
	for (i = 0; i < 64; i++)
		cout << de1;
	gotoxy(9, 5);
	box(16, 65);
	gotoxy(13, 9);
	box(4, 27);
	gotoxy(14, 11);
	cout << "1)New And Regular customer";
	gotoxy(43, 9);
	box(4, 27);
	gotoxy(44, 11);
	cout << "2)Existing customer";
	gotoxy(13, 15);
	box(4, 27);
	gotoxy(14, 17);
	cout << "3)New Guest";
	gotoxy(43, 15);
	box(4, 27);
	gotoxy(44, 17);
	cout << "4)View history of toll";
	de1 = getch();
	if (de1 == '0')
		exit(0);
	if (de1 == 'm' || de1 == 'M')
		goto start;
	if (de1 != '1' && de1 != '2' && de1 != '3' && de1 != '4' && de1 != '0')
	{
		error();
		char d = getch();
		if (d == '0')
			goto start;
		if (d == '1')
			goto tolhome;
	}
	if (de1 == '1')
	{
		cus.getdata();
		ofstream ofs;
		ofs.open("requestedCustomers.dat", ios::binary | ios::app);
		ofs.write((char *)&cus, sizeof(cus));
		ofs.close();
		char tfname[20];
		strcpy(tfname, tname);
		strcat(tfname, ".txt");
		ofs.open(tfname, ios::app);
		ofs << "\n"
			<< cus.veh_no << "     " << cus.veh_type << "     n";
		ofs.close();
		goto tolhome;
	}
	if (de1 == '2')
	{
	ulog:
		flag = 0;
		system("cls");
		char uname[20], upword[20];
		adminlogin();
		gotoxy(6, 5);
		cout << "CUSTOMER LOGIN WINDOW";
		ifstream ifs;
		gotoxy(25, 13);
		cout << "Enter Username : ";
		int x = wherex();
		gotoxy(25, 14);
		cout << "Enter Password : ";
		int x1 = wherex();
		gotoxy(x, 13);
		gets(uname);
		ifs.open("permanentCustomers.dat", ios::binary);
		while (!ifs.eof())
		{
			ifs.read((char *)&cus, sizeof(cus));
			if (ifs.eof())
				break;
			if (strcmp(cus.username, uname) == 0)
			{
				flag = 1;
				gotoxy(55, 13);
				cout << "matched";
				ifs.close();
				goto upass;
			}
		}
		ifs.close();
		if (flag == 0)
		{
			error();
			char d = getch();
			if (d == '1')
				goto ulog;
			if (d == '0')
				goto start;
		}
	upass:
		gotoxy(x1, 14);
		for (i = 0;; i++)
		{
			c = getch();
			if (c == '\r')
			{
				upword[i] = '\0';
				break;
			}
			if (c == '\b')
			{
				int x, y;
				x = wherex();
				y = wherey();
				gotoxy(x - 1, y);
				cout << " ";
				gotoxy(x - 1, y);
				i -= 2;
			}
			else
			{
				upword[i] = c;
				cout << "*";
			}
		}
		flag = 0;
		fstream fs;
		long t;
		fs.open("permanentCustomers.dat", ios::binary | ios::in | ios::out);
		while (!fs.eof())
		{
			t = fs.tellg();
			fs.read((char *)&cus, sizeof(cus));
			if (fs.eof())
				break;
			if (strcmp(cus.username, uname) == 0 && strcmp(cus.password, upword) == 0)
			{
				flag = 1;
				gotoxy(55, 14);
				cout << "matched";
				gotoxy(23, 19);
				cout << "Press any key";
				getch();
				if (cus.price_card < cus.veh_amt)
				{
					system("cls");
					gotoxy(15, 10);
					cout << "NOT ENOUGH MONEY";
					gotoxy(15, 11);
					cout << "ASK CUSTOMER TO RECHARGE CARD";
					gotoxy(15, 12);
					cout << "PRESS P IF YOU GOT CASH";
					gotoxy(15, 13);
					cout << "PRESS ANY KEY TO GO HOME";
					char g;
					g = getch();
					if (g == 'p' || g == 'P')
					{
						goto skp;
					}
					else
						goto tolhome;
				}
				fs.seekg(t);
				cus.veh_price();
				fs.write((char *)&cus, sizeof(cus));
			skp:
				char tfname[20];
				strcpy(tfname, tname);
				strcat(tfname, ".txt");
				ofstream ofs;
				ofs.open(tfname, ios::app);
				ofs << "\n"
					<< cus.veh_no << "     " << cus.veh_type << "     e";
				ofs.close();
				char flname[20];
				strcpy(flname, cus.username);
				strcat(flname, ".txt");
				ofs.open(flname, ios::app);
				ofs << "\n"
					<< tname << " toll"
					<< " AMT DEBITED";
				ofs.close();
				goto tolhome;
			}
		}
		fs.close();
		if (flag == 0)
		{
			gotoxy(55, 13);
			cout << "not matched";
			gotoxy(23, 19);
			cout << "Press any key";
			getch();
		lt:
			error();
			d = getch();
			if (d == '1')
			{
				adminlogin();
				gotoxy(6, 6);
				cout << "TOLL LOGIN WINDOW";
				gotoxy(::x, 13);
				puts(tname);
				goto upass;
			}
			if (d == '0')
			{
				goto start;
			}
			else
			{
				cout << "\n\n\t\tINVALID CHOICE";
				cout << "\nPRESS ANY KEY";
				getch();
				goto lt;
			}
		}
	}
	if (de1 == '3')
	{
		char vno[30], vty[30];
		system("cls");
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(15, 5);
		cout << "Enter vehicle number : ";fflush(stdin);
		gets(vno);
		gotoxy(15, 6);
		cout << "Enter vehicle type : ";fflush(stdin);
		gets(vty);
		char tfname[20];
		ofstream ofs;
		strcpy(tfname, tname);
		strcat(tfname, ".txt");
		ofs.open(tfname, ios::app);
		ofs << "\n"
			<< vno << "     " << vty << "     g";
		ofs.close();
		gotoxy(23, 12);
		cout << " Job Done Successfully";
		gotoxy(25, 13);
		cout << "Press Any Key";
		getch();
		goto tolhome;
	}
	if (de1 == '4')
	{
		system("cls");
		int y = 7, co = 0;
		gotoxy(1, 1);
		wave();
		gotoxy(1, 22);
		wave();
		gotoxy(3, 6);
		cout << "PASSED HISTORY                     MENU(M)                          CLOSE(0)";
		gotoxy(3, 7);
		char de = 205;
		for (int i = 0; i < 76; i++)
			cout << de;
		gotoxy(2, 5);
		box(16, 78);
		gotoxy(3, 8);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 10);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 12);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 14);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 16);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 18);
		for (i = 0; i < 76; i++)
			cout << de;
		gotoxy(3, 20);
		for (i = 0; i < 76; i++)
			cout << de;
		y = 7;
		ifstream ifs;
		char c, str[30], tfname[20];
		strcpy(tfname, tname);
		strcat(tfname, ".txt");
		ifs.open(tfname);
		while (!ifs.eof())
		{
			ifs.get(c);
			cout << c;
			if (c == '\n')
			{
				gotoxy(4, y += 2);
				cout << "                                                      ";
				gotoxy(4, y);
				co++;
			}
			if (co > 6)
			{
				co = 0;
				y = 7;
			}
		}
		ifs.close();
		gotoxy(4, 21);
		cout << "Press any key                          ";
		getch();
		goto tolhome;
	}
	return 0;
}
