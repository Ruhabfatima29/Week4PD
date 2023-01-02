#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy( int x, int y);
void printName();
main()
{
   printName();   
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printName()
{
   gotoxy(15,15);
   cout << "  #######         ##       ##      ##        ##       ####      ######## " ;
   gotoxy(15,16);
   cout << "  ##    ##        ##       ##      ##        ##     ##    ##    ##    ##   " ;
   gotoxy(15,17);
   cout << "  ##   ##         ##       ##      ##        ##     ##    ##    ##    ## " ;
   gotoxy(15,18);
   cout << "  ##  ##          ##       ##      ############     ########    ####### " ;
   gotoxy(15,19);
   cout << "  ####            ##       ##      ##        ##     ##    ##    ##    ##" ;
   gotoxy(15,20);
   cout << "  ##  ##           ##     ##       ##        ##     ##    ##    ##    ##  ";
   gotoxy(15,21);
   cout << "  ##   ####          #####         ##        ##     ##    ##    ####### ";
}

