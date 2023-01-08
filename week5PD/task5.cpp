#include<iostream>
#include<windows.h>
using namespace std;

void printMaze();
void erasePacman(int x, int y);
void printPacman(int x, int y);
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

main()
{
  int x = 4;
  int y = 4;
  bool gameRunning = true;
  system("cls");
  printMaze();
  gotoxy(x,y);
  cout << "P";
  while(gameRunning)
  {  
  if(GetAsyncKeyState(VK_RIGHT))
  {
     char nextLocation = getCharAtxy(x+1, y);
     if( nextLocation == ' ')
     {
     erasePacman(x,y);
     x = x+1;
     printPacman(x,y);
     }
  }
  if(GetAsyncKeyState(VK_LEFT))
  {
     char nextLocation = getCharAtxy(x-1, y);
     if( nextLocation == ' ')
    {
     erasePacman(x,y);
     x = x-1;
     printPacman(x,y);
    }
  }
  if(GetAsyncKeyState(VK_UP))
  {
     char nextLocation = getCharAtxy(x, y-1);
     if( nextLocation == ' ')
     {
     erasePacman(x,y);
     y = y-1;
     printPacman(x,y);

     }
  }
 if(GetAsyncKeyState(VK_DOWN))
 {
     
     char nextLocation = getCharAtxy(x, y+1);
     if( nextLocation == ' ')
     {
     erasePacman(x,y);
     y = y+1;
     printPacman(x,y);
     }
 } 
 if (GetAsyncKeyState(VK_ESCAPE))
 {
   gameRunning = false;
 }
  Sleep(200);
}


}
void printMaze()
{
cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$                                    $"<< endl;
cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;
}
char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void erasePacman(int x, int y)
{

 gotoxy(x,y);
 cout << " ";
    

}
void printPacman(int x, int y)
{
    gotoxy(x,y);
    cout << "P";
}



