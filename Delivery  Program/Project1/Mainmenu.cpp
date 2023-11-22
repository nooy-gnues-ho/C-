#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <string>
#include <ctime>
#include "OrderStatus.h"
#include "ConSole.h"
#include "Mainmenu.h"
#include "global.h"
#include "FoodStatus.h"
using namespace std;
int	startKey = 0;
string mw[8]; 
string foodq[12];



void Menu::moveWay() 
{

	int food[12];
	string re;
	int count = 1, i =1;
	for (int i = 1; i < 11; i++)
		if (mw[count] > 0)
			count++;

	mw[count] = startKey; 
	cout<< " 주문 할 메뉴를 선택하세요(입력 종료:0):";

	for ( i = 1; i < 11; i++)
	{
		cin >> food[i];
		menuKey[count][i] = food[i];

		if (food[i] == 1)
			totalprice[count] += 5000;

		else if (food[i] == 2 || food[i] == 6 || food[i] == 8)
			totalprice[count] += 8000;

		else if (food[i] == 3 || food[i] == 4 || food[i] == 5 || food[i] == 9 || food[i] == 10)
			totalprice[count] += 10000;

		else if (food[i] == 7)
			totalprice[count] += 9000;

		if (food[i] == 0)
			break;
		food[i] = 0;
	}
	if (menuKey[count][1] == 0)
	{
		mw[count] = 0;
		system("cls");
		return;
	}
	else
	{
		cout << "원하시는 요구사항이 있습니까? (입력중단시 'x' 입력): " << endl;

		getline(cin, re, '\n');
		getline(cin, re, '\n');
		requirements[count] = re;

		system("cls");
	}
}



void Menu::alter(void)
{
	system("cls");

	int fooda[12];
	string re;
	int tnwjd = 0;
	Orderlist s;
	int i = 0,a;
	a=show();
	if (a == 1)
	{
		system("cls");
		return;
	}
	cout << "수정할 주문 선택(이전 0) : ";
	cin >> tnwjd;
	if (tnwjd == 0)
	{
		system("cls");
		return;
	}
	cout << "주문타입을 입력해주세요 픽업(1), 매장(2), 주문취소(0) : ";
	mw[tnwjd] = 0;
	cin >> mw[tnwjd];
	if (mw[tnwjd] == 0)
	{
		system("cls");
		gotoxy(10, 10);
		cout << "주문이 취소되었습니다" << endl;
		requirements[tnwjd].clear();
		mw[tnwjd] = 0;
		Sleep(1500);
		system("cls");
		return;
	}
	system("cls");
	menuScreen();
	cout << "음식을 입력해주세요 (주문취소(0)): ";
	totalprice[tnwjd] = 0;
	for ( i = 1; i < 11; i++)
		menuKey[tnwjd][i] = 0;
	for ( i = 1; i < 11; i++)//음식주문받는부분
	{
		cin >> fooda[i];
		menuKey[tnwjd][i] = fooda[i];//음식수정주문번호

		if (fooda[i] == 1)
			totalprice[tnwjd] += 5000;

		else if (fooda[i] == 2 || fooda[i] == 6 || fooda[i] == 8)
			totalprice[tnwjd] += 8000;

		else if (fooda[i] == 3 || fooda[i] == 4 || fooda[i] == 5 || fooda[i] == 9 || fooda[i] == 10)
			totalprice[tnwjd] += 10000;

		else if (fooda[i] == 7)
			totalprice[tnwjd] += 9000;

		if (fooda[i] == 0)
			break;
		fooda[i] = 0;
	}

	
		cout << "요구사항을 입력해주세요 (입력중단시 'x' 입력): " << endl;

		getline(cin, re, '\n');
		getline(cin, re, '\n');
		requirements[tnwjd] = re;
		system("cls");
		gotoxy(10, 10);
		cout << "주문수정이 완료되었습니다" << endl;
		Sleep(1500);
		system("cls");
	
}
int Menu::show()
{
	int q;
	system("cls");
	if (mw[1] == 0)
	{
		gotoxy(10, 10);
		cout << "주문이 없습니다!" << endl;
		Sleep(1500);
		return 1;
	}
	else
	{
		cout << endl;
		for (int i = 1; i < 11; i++)
		{
			cout << i << "." << "   ";
			if (mw[i] == 1)
				cout << "픽업주문, ";
			else if (mw[i] == 2)
				cout << "매장주문, ";
			for (int j = 1; j < 11; j++)
			{
				if (menuKey[i][j] == 1)
					cout << "떡볶이, ";
				else if (menuKey[i][j] == 2)
					cout << "닭갈비, ";
				else if (menuKey[i][j] == 3)
					cout << "갈비탕, ";
				else if (menuKey[i][j] == 4)
					cout << "설렁탕, ";
				else if (menuKey[i][j] == 5)
					cout << "추어탕, ";
				else if (menuKey[i][j] == 6)
					cout << "불고기, ";
				else if (menuKey[i][j] == 7)
					cout << "비빔밥, ";
				else if (menuKey[i][j] == 8)
					cout << "제육볶음, ";
				else if (menuKey[i][j] == 9)
					cout << "김치찌개, ";
				else if (menuKey[i][j] == 10)
					cout << "된장찌개, ";
			}
			if (totalprice[i] != 0)
				cout << "총금액: " << totalprice[i] << "  ";
			if (empty(requirements[i]) == 0)
				cout << "요구사항 : " << requirements[i];
			cout << endl;
			
		}
	}
}


void menuScreen()  //메뉴판
{
	cout << "빨간글씨 메뉴는 선택하실 수 없습니다" << endl;
	for (int i = 1; i < 11; i++)
	{
		if (Checklist[i] == i)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << i << ": " << foodF[i] << "\t" << "가격 : " << PriceF[i] <<  endl;
			Checklist1[i] = i;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << i << ": " << foodF[i] << "\t" << "  가격 : " << PriceF[i] <<  endl;
		}
		cout << endl ;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	cout << "-------------------------------------------------" << endl;
}

void Menu::order()
{
	system("cls");
	while (1)
	{
		gotoxy(1, 3); cout << "1.픽업주문" << endl;
		gotoxy(1, 6); cout << "2.배달주문" << endl;
		gotoxy(1, 9); cout << "3.주문내역 수정" << endl;
		gotoxy(1, 12); cout << "4.이전" << endl;

		gotoxy(1, 21); cout << "입력: ";

		cin >> startKey;

		switch (startKey) {
		case 1:
			system("cls");
			menuScreen();
			moveWay();
			break;
		case 2:
			system("cls");
			menuScreen();
			moveWay();
			break;
		case 3:
			system("cls");
			alter();
			break;
		case 4:
			system("cls");
			return;
		}
	}
}
void Menu::Calculation()
{
	timer = time(NULL);
	t = localtime(&timer);
	int num = 0;
	cout << " --------------------------------------------------------------------------------" << endl;
	cout << "주문을 선택해 주세요(결재취소 0):";
	cin >> num;
	if (num == 0)
		return;
	cout << "결제하실 금액은 :" << totalprice[num] << endl;
	Sleep(2000);
	daysales += totalprice[num];
	monthsales += totalprice[num];
	cout << t->tm_year + 1900 << "." << t->tm_mon + 1 << "." << t->tm_mday << endl << "당일 매출액은 : " << daysales << "원 입니다." << endl;
	cout << t->tm_year + 1900 << "." << t->tm_mon + 1 << "월" << endl << "당월 매출액은 : " << monthsales << "원 입니다." << endl;

	mw[num] = 0;
	totalprice[num] = 0;

	for (int i = 0; i < 10; i++)
		menuKey[num][i] = 0;

	requirements[num].clear();



}
