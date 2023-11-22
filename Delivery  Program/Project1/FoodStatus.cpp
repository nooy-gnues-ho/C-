#include <iostream>
#include <string>
#include <Windows.h>
#include "FoodStatus.h"
#include "global.h"
#include "Mainmenu.h"
#include "ConSole.h"
using namespace std;
void foodlist()
{
	while (1)
	{
	
		for (int i = 1; i < 11; i++)
		{
			if (Checklist[i] == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << i << ": " << foodF[i] << "\t" << "가격 : " << PriceF[i] << endl;
				Checklist1[i] = i;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << i << ": " << foodF[i] << "\t" << "  가격 : " << PriceF[i] << endl;
			}
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " -----------------------------------------------------------------------------------------" << endl;

		gotoxy(0, 21);
		cout << " 상태를 변경할 매뉴를 선택하세요. 이전(0): ";
		cin >> State;
		if (State == 0)
		{
			system("cls");
			break;
		}
		Checklist[State] = State;
		if (Checklist1[State] == State)
		{
			Checklist[State] = 15;
			Checklist1[State] = 0;
		}
		system("cls");
	}
}
	
