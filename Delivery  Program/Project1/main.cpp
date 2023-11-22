#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include "MainScreen.h"
#include "global.h"
#include "OrderStatus.h"
#include "Mainmenu.h"
#include "StoreStatus.h"
#include "FoodStatus.h"
#include "ConSole.h"
using namespace cv;
using namespace std;
Menu one;
int num=0;

int main()
{
	SetConsoleView();
	Mat img = imread("foodpicture.jpeg"); 

	while (1)
	{
		startScreen(); //시작화면
		cin >> MainKey;
		system("cls");
		switch (MainKey)
		{
		case 1:
			system("cls");
			one.order();
			system("cls");
			break;
		case 2:
			system("cls");
			one.show();
			gotoxy(1, 21); cout << "이전으로 이동 (0) ";
			cin >> MainKey;
			system("cls");
			break;
		case 3:
			system("cls");
			one.show();
			if (one.mw[1] != 0)
				one.Calculation();
			system("cls");
			break;
		case 4:
			system("cls");
			Storestaus();
			system("cls");
			break;
		case 5:
			system("cls");
			foodlist();
			system("cls");
			break;
		case 6:
			imshow("img", img);
			waitKey(0);
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "프로그램 종료 " << endl;
			return 0;
		}
	}
}