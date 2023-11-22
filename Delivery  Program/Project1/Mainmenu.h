#pragma once
#include <string>
class Menu {
public:
	void moveWay(void);
	int menuKey[12][12]; 
	void alter(void);
	std::string revision;
	int mw[12] = { 0 };
	int totalprice[12] = { 0 }; 
	std::string requirements[12]; 
	int show();
	void order();
	void Calculation();

};
void menuScreen();
