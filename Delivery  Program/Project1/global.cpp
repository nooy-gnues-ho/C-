#include <string>
using namespace std;
int MainKey=0; 
int State = 15; 
int Checklist[15] = { 0 }; 
int Checklist1[15] = { 0 };
string stop="x";
int daysales=0;
int monthsales=0;
time_t timer;
struct tm* t;
string foodF[] = { "","¶±ººÀÌ","´ß°¥ºñ", "°¥ºñÅÁ","¼³··ÅÁ", "Ãß¾îÅÁ" , "ºÒ°í±â","ºñºö¹ä", "Á¦À°ººÀ½","±èÄ¡Âî°³","µÈÀåÂî°³", };
int PriceF[] = { 0,5000 , 8000 , 10000, 10000, 10000,10000,9000,8000,8000,10000,10000 };
