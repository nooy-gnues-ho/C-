#pragma once
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void SetConsoleView();
void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);
