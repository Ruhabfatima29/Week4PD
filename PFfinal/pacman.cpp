#include <iostream>
#include <windows.h>
using namespace std;

void printMaze();
void erasePacman(int x, int y);
void printPacman(int x, int y);
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void clear(int x, int y, char previous);
void showGhost(int x, int y);
void returnScore(int);
main()
{
    int score = 0 , sum = 0 ;
    int x = 4;
    int y = 4;
    int gx = 3;
    int gy = 16;
    int x2 = 54;
    int y2 = 10;
    string direction = "right";
    string direction2 = "up";
    char previousChar = ' ';
    bool gameRunning = true;
    system("cls");
    printMaze();
    gotoxy(x, y);
    cout << "P";
    showGhost(gx, gy);
    showGhost(x2, y2);
    while (gameRunning)
    {
        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = getCharAtxy(x + 1, y);
            if (nextLocation == ' ' || nextLocation == '.')
            {
                erasePacman(x, y);
                x = x + 1;
                printPacman(x, y);
                if (nextLocation == '.')
                {
                    sum = sum + 5;
                    returnScore(sum);
                }
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            char nextLocation = getCharAtxy(x - 1, y);
            if (nextLocation == ' ' || nextLocation == '.')
            {
                erasePacman(x, y);
                x = x - 1;
                printPacman(x, y);
                if (nextLocation == '.')
                {
                    sum = sum + 5;
                    returnScore(sum);
                }
            }
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            char nextLocation = getCharAtxy(x, y - 1);
            if (nextLocation == ' ' || nextLocation == '.')
            {
                erasePacman(x, y);
                y = y - 1;
                printPacman(x, y);
                if (nextLocation == '.')
                {
                    sum = sum + 5;
                    returnScore(sum);
                }
            }
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {

            char nextLocation = getCharAtxy(x, y + 1);
            if (nextLocation == ' ' || nextLocation == '.')
            {
                erasePacman(x, y);
                y = y + 1;
                printPacman(x, y);
                if (nextLocation == '.')
                {
                    sum = sum + 5;
                    returnScore(sum);
                }
            }
        }

        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }
        Sleep(200);
        if (direction == "right")
        {
            char nextLocation = getCharAtxy(gx + 1, gy);
            if (nextLocation == '%' || nextLocation == '|')
            {
                direction = "Left";
            }
            else if (nextLocation == ' ' || nextLocation == '.')
            {
                clear(gx, gy, previousChar);
                gx = gx + 1;
                previousChar = nextLocation;
                showGhost(gx, gy);
            }
        }
        if (direction == "Left")
        {

            char nextLocation = getCharAtxy(gx - 1, gy);
            if (nextLocation == '%' || nextLocation == '|')
            {
                direction = "right";
            }
            else if (nextLocation == ' ' || nextLocation == '.')
            {
                clear(gx, gy, previousChar);
                gx = gx - 1;
                previousChar = nextLocation;
                showGhost(gx, gy);
            }
        }
        if (direction2 == "up")
        {
            char nextLocation = getCharAtxy(x2, y2 - 1);
            if (nextLocation == '%' || nextLocation == '#')
            {
                direction2 = "down";
            }
            else if (nextLocation == ' ' || nextLocation == '.')
            {
                clear(x2, y2, previousChar);
                y2 = y2 - 1;
                previousChar = nextLocation;
                showGhost(x2, y2);
            }
        }
        if (direction2 == "down")
        {
            char nextLocation = getCharAtxy(x2, y2 + 1);
            if (nextLocation == '%' || nextLocation == '#')
            {
                direction2 = "up";
            }
            else if (nextLocation == ' ' || nextLocation == '.')
            {
                clear(x2, y2, previousChar);
                y2 = y2 + 1;
                previousChar = nextLocation;
                showGhost(x2, y2);
            }
        }
    }
}

void printMaze()
{

    cout << " ########################################################################   " << endl;
    cout << " ||.. ............................------....................... ...... ||   " << endl;
    cout << " ||.. %%%%%%%%%%%%%%%%%%%     ...       %%%%%%%%%%%%%%%%  |%|.. %%%%%  ||   " << endl;
    cout << " ||..          |%|    |%|  |%|...       |%|          |%|  |%|..   |%|  ||   " << endl;
    cout << " ||..          |%|    |%|  |%|...       |%|          |%|  |%|..   |%|  ||   " << endl;
    cout << " ||..          %%%%%%%%% ..|%|...       %%%%%%%%%%%%%%%%     .. %%%%%. ||   " << endl;
    cout << " ||..          |%|       ..|%|...      ................. |%| ..      . ||   " << endl;
    cout << " ||..          %%%%%%%%% ..|%|...      %%%%%%%%%%%%%%    |%| .. %%%%%. ||   " << endl;
    cout << " ||..                |%| .             |%|.......        |%| ..    |%|.||   " << endl;
    cout << " ||..     .......... |%| .             |%|.......|%|         ..    |%|.||   " << endl;
    cout << " ||..|%|  |%|%%%%|%|.|%| .|%|             .......|%|         ..|%| |%|.||   " << endl;
    cout << " ||..|%|  |%|    |%|..    %%%%%%%%%%%%%%  .......|%|          .|%|.    ||   " << endl;
    cout << " ||..|%|  |%|    |%|..           ....|%|     %%%%%%          . |%|.    ||   " << endl;
    cout << " ||..|%|             .           ....|%|                 |%| ..|%|.    ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%%        ....|%|%%%%%%%%%%%      |%| ..|%|%%%% ||   " << endl;
    cout << " ||................................................      |%| ......... ||   " << endl;
    cout << " ||   .............................................             ...... ||   " << endl;
    cout << " ||..|%|  |%|     |%|..    %%%%%%%%%%%%%    ....|%|      |%| ..|%|.    ||   " << endl;
    cout << " ||..|%|  |%|     |%|..          ....|%|      %%%%%      |%| ..|%|.    ||   " << endl;
    cout << " ||..|%|              .          ....|%|                 |%| ..|%|.    ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%%%       ....|%|%%%%%%%%%%       |%| ..|%|%%%%%||   " << endl;
    cout << " ||.................................................     |%| ..........||   " << endl;
    cout << " ||  ...............................................            .......||   " << endl;
    cout << " ########################################################################   " << endl;
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

    gotoxy(x, y);
    cout << " ";
}
void printPacman(int x, int y)
{
    gotoxy(x, y);
    cout << "P";
}
void clear(int x, int y, char previous)
{
    gotoxy(x, y);
    cout << previous;
}
void showGhost(int x, int y)
{
    gotoxy(x, y);
    cout << "G";
}
void returnScore(int score)
{
    int x, y;
    x = 60;
    y = 24;
    gotoxy(x, y);
    cout << "Score : " << score;
}