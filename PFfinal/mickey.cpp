#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
// Functions prototypes
void header();
string logo();
string headerMenu();
void game();
void keysFunctions();
void instructMenu();
void gotoxy(int x, int y);
// Function prototypes for Boombie
void printBoombieBullet(int &x, int &y);
void eraseBoombieBullet(int &x, int &y);
void moveBoombieBullet(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount);
void boombieBulletDetectionwithMickey(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount, int &mickeyX, int &mickeyY, int &mickeyHealth);
void makeBoombieBulletInactive(int index, bool isBoombieBulletActive[]);
// Functions for Mickey
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index, bool isBulletActive[]);
void createBoombieBullet(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount, int &boombieX, int &boombieY);
void mickeyHeader();
void printScore(int &score);
void printMickeyHealth(int &mickeyHealth);
void printMickeyLife(int &mickeyLife);
void printKeys(int &key);
// Functions for Stinky
void createStinkyBullet(int &stinkyX, int &stinkyY, bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount);
void printStinkyBullet(int x, int y);
void eraseStinkyBullet(int x, int y);
void makeStinkyBulletInactive(int index, bool isStinkyBulletActive[]);
void moveStinkyBullet(bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount);
// Functions for Theif
void createTheifBullet(int &theifX, int &theifY, int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount);
void printTheifBullet(int x, int y);
void eraseTheifBullet(int x, int y);
void makeTheifBulletInactive(int index, bool isTheifBulletActive[]);
void moveTheifBullet(int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount);
void theifBulletDetectionwithMickey(int &mickeyX, int &mickeyY, int &key, int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount);
// Functions for Maze
void loadDataFromMazeFile();
void storeDataToResumeFile();
string maze[30][116];
void printMaze(string arr[][116], int row, int col);

// to print and erase funtions prototypes
void printTheif(int &theifX, int &theifY);
void eraseThief(int &theifX, int &theifY);
void printStinky(int &stinkyX, int &stinkyY);
void eraseStinky(int &stinkyX, int &stinkyY);
char getCharAtxy(short int x, short int y);
void printBoombie(int &boombieX, int &boombieY);
void eraseBoombie(int &boombieX, int &boombieY);
void printMickey(int &mickeyX, int &mickeyY);
void eraseMickey(int &mickeyX, int &mickeyY);
void createBullet(int &mickeyX, int &mickeyY, int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount);
// movement functions prototypes
void moveMickeyUp(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key);
void moveMickeyDown(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key);
void moveMickeyLeft(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key);
void moveMickeyRight(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key);
void moveStinky(int &stinkyX, int &stinkyY, string &stinkyDirection);
void moveBoombie(int &boombieX, int &boombieY, string &boombieDirection);
void moveBullet(int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount);
void moveTheif(int &theifX, int &theifY, int &theifDirection);

void StinkyBulletDetectionwithMickey(int &mickeyX, int &mickeyY, int &mickeyHealth, bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount);
void loadDataFromMazeFile();
void mickBulletDetectionwithEnemies(int &boombieX, int &boombieY, int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount, int &stinkyX, int &stinkyY, int &score, int &theifX, int &theifY);
// function definitions
main()
{

    string option = "0";
    while (option != "4")
    {
        system("cls");
        option = logo();
        if (option == "1")
        {
            string choice = "0";
            while (choice != "3")
            {
                system("cls");
                header();
                choice = headerMenu();
                if (choice == "1")
                {
                    // print keys functionality
                    keysFunctions();
                }
                if (choice == "2")
                {
                    // print instructions menu]
                    instructMenu();
                }
                Sleep(100);
                getch();
            }
        }
        else if (option == "2")
        {
            // Start game
            system("cls");
            mickeyHeader();
            gotoxy(55, 25);
            cout << "Loading";
            int num = 0;
            while (num != 7)
            {
                cout << ".";
                Sleep(1000);
                num++;
            }
            game();
        }
        else if (option == "3")
        {

            system("cls");
            mickeyHeader();
            gotoxy(55, 25);
            cout << "Loading";
            int num = 0;
            while (num != 7)
            {
                cout << ".";
                Sleep(1000);
                num++;
            }
            game();
        }
        Sleep(100);
        getch();
    }
}
void header()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
   

    cout << "  [[]][[]]     [[]][[]]  [[[[]]]]      [[[]]]   []      []   [[[[]]]]   [[]]     [[]]" << endl;
    cout << "    [][]         [][]       ||       []         ||     []    ||           []     []" << endl;
    cout << "    [][]  []  [] [][]       ||      []          ||    []     ||            []   []" << endl;
    cout << "    [][]    []   [][]       ||      []          ||[][]       ||[[]]          [[]]" << endl;
    cout << "    [][]   [][]  [][]       ||      []          ||   []      ||               []" << endl;
    cout << "    [][]         [][]       ||       []         ||    []     ||               []" << endl;
    cout << "   [[][]]       [[][]]   [[[[]]]]      [[[]]]   []      []   [[[[]]]]       [[[]]]" << endl
         << endl;

    cout << "                                         [[[[]]]]  [[]]   [[]]  [[[[]]]]           " << endl;
    cout << "                                            ||      ||     ||   ||             " << endl;
    cout << "                                            ||      ||[[[]]]|   ||[[]]         " << endl;
    cout << "                                            ||      ||     ||   ||               " << endl;
    cout << "                                            ||      ||     ||   ||              " << endl;
    cout << "                                            []     [[]]   [[]]  [[[[]]]]       " << endl
         << endl;

    cout << "                              [[[[]]]]     [[[]]]   [[]]      [[]]   [[[[]]]]    [[[]]]    [[[[]]]]      " << endl;
    cout << "                             []           []    []   ||        ||       ||      []    []    ||    ||      " << endl;
    cout << "                             []           ||    ||   ||        ||       ||      []    []    ||  ||        " << endl;
    cout << "                              [[[]]]]     ||[[]]||    ||      ||        ||      []    []    [[]]         " << endl;
    cout << "                                    []    ||    ||     ||    ||         ||      []    []    ||  ||           " << endl;
    cout << "                                    []    []    []      ||  ||          ||      []    []    ||   ||           " << endl;
    cout << "                             [][[[]]]    [[]]  [[]]       []         [[[[]]]]    [[[]]]    [[]]  [[]]            " << endl;
}
string headerMenu()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    string choice;
    cout << endl
         << "________________________________________________________________________________________________________________" << endl;

    cout << "1. Keys Funtions " << endl;
    cout << "2. Game Instructions " << endl;
    cout << "3. Exit " << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}
void keysFunctions()
{
    system("cls");
    cout << "****************************************************************************" << endl;
    cout << "*                          KEYS FUNCTIONALITY                              * " << endl;
    cout << "****************************************************************************" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl
         << endl;
    cout << " KEYS                          FUNCTIONALITY " << endl
         << endl;

    cout << "1. UP                          MOVE UP " << endl;
    cout << "2. DOWN                        MOVE DOWN " << endl;
    cout << "3. LEFT                        MOVE LEFT " << endl;
    cout << "4. RIGHT                       MOVE RIGHT " << endl;
    cout << "5. ENTER                       FOR FIRING ENEMIES " << endl;
    cout << "6. ESCAPE                      TO EXIT GAME " << endl;
}
void instructMenu()
{
    system("cls");
    cout << "****************************************************************************" << endl;
    cout << "*                          INSTRUCTIONS MENU                               * " << endl;
    cout << "****************************************************************************" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl
         << endl
         << endl;

    cout << " The player can fire the enemies by pressing space key. On firing enemies, the\n score will be increased. ";
    cout << "There are keys(k) spread on the maze, you have to collect \nthem. There are also some energy boosters on the screen";
    cout << "On getting energy booster\n your health will be increased by 10. There are three enemies in the maze.\n ";
    cout << "The most dangerous one is Boombie, on getting hit by its bullet,\n your health will be decreased by 5";
    cout << "Another enemie is stinky, on getting \n hit by its bullet, your health will be decreased by 2";
    cout << "The last enemie is \n theif, on getting hit by its bullet, your keys will be decreased by 1 ";
}
void printStinky(int &stinkyX, int &stinkyY)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    char head = 1;
    char body = 178;
    char arrow = 174;
    char b = 185;
    char c = 186;
    char stinky[3][6] = {
        {' ', ' ', head, ' ', ' ', ' '},
        {arrow, b, body, body, '>'},
        {' ', ' ', c, c, ' ', ' '}};
    for (int row = 0; row < 3; row++)
    {
        gotoxy(stinkyX, stinkyY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << stinky[row][col];
        }
    }
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
void game()
{
    int mickeyX = 3;
    int mickeyY = 10;
    int theifX = 20;
    int theifY = 25;
    int stinkyTimer = 1;
    int bulletCount = 0;
    int mickBulletX[2000];
    int mickBulletY[2000];
    int boombieBulletX[2000];
    int boombieBulletY[2000];
    int boombieTimer = 0;
    int boomieBulletCount = 0;
    int theifTimer = 0;
    int boombieX = 5;
    int boombieY = 2;
    int mickeyHealth = 50;
    int stinkyX = 90;
    int stinkyY = 20;
    bool isStinkyBulletActive[2000];
    int mickeyLife = 3;
    bool isBulletActive[2000];
    bool isBoombieBulletActive[2000];
    int stinkyBulletX[2000];
    int stinkyBulletY[2000];
    int stinkyBulletCount = 0;
    int score = 0;
    int key = 0;
    int theifBulletX[2000];
    int theifBulletY[2000];
    bool isTheifBulletActive[2000];
    int theifBulletCount = 0;
    string stinkyDirection = "Down";
    int theifDirection = 0;
    string boombieDirection = "Right";
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 228);
    loadDataFromMazeFile();
    printMaze(maze, 30, 116);
    printStinky(stinkyX, stinkyY);
    printBoombie(boombieX, boombieY);
    printTheif(theifX, theifY);
    printMickey(mickeyX, mickeyY);
    bool gameRunning = true;
    while (gameRunning == true)
    {
        printScore(score);
        printMickeyHealth(mickeyHealth);
        printMickeyLife(mickeyLife);
        printKeys(key);
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveMickeyLeft(mickeyX, mickeyY, mickeyHealth, key);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveMickeyRight(mickeyX, mickeyY, mickeyHealth, key);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveMickeyUp(mickeyX, mickeyY, mickeyHealth, key);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveMickeyDown(mickeyX, mickeyY, mickeyHealth, key);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            createBullet(mickeyX, mickeyY, mickBulletX, mickBulletY, isBulletActive, bulletCount);
        }
        if (stinkyTimer == 6)
        {
            moveStinky(stinkyX, stinkyY, stinkyDirection);
            stinkyTimer = 0;
        }
        if (theifTimer == 5)
        {
            createTheifBullet(theifX, theifY, theifBulletX, theifBulletY, isTheifBulletActive, theifBulletCount);
            theifTimer = 0;
        }
        createStinkyBullet(stinkyX, stinkyY, isStinkyBulletActive, stinkyBulletX, stinkyBulletY, stinkyBulletCount);
        createBoombieBullet(boombieBulletX, boombieBulletY, isBoombieBulletActive, boomieBulletCount, boombieX, boombieY);
        if (mickeyHealth <= 0 && mickeyLife > 0)
        {
            mickeyHealth = 50;
            mickeyLife--;
        }
        if (mickeyLife == 0 && mickeyHealth <= 0)
        {
            gameRunning = false;
            mickeyLife = 3;
            mickeyHealth = 50;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            storeDataToResumeFile();
            gameRunning = false;
        }
        if (key >= 12)
        {
            gotoxy(120, 20);
            cout << "You Won";
            Sleep(200);
            gameRunning = false;
            getch();
        }
        moveStinkyBullet(isStinkyBulletActive, stinkyBulletX, stinkyBulletY, stinkyBulletCount);
        moveBoombie(boombieX, boombieY, boombieDirection);
        moveTheifBullet(theifBulletX, theifBulletY, isTheifBulletActive, theifBulletCount);
        boombieTimer++;
        stinkyTimer++;
        theifTimer++;
        moveBoombieBullet(boombieBulletX, boombieBulletY, isBoombieBulletActive, boomieBulletCount);
        moveTheif(theifX, theifY, theifDirection);
        moveBullet(mickBulletX, mickBulletY, isBulletActive, bulletCount);
        StinkyBulletDetectionwithMickey(mickeyX, mickeyY, mickeyHealth, isStinkyBulletActive, stinkyBulletX, stinkyBulletY, stinkyBulletCount);
        mickBulletDetectionwithEnemies(boombieX, boombieY, mickBulletX, mickBulletY, isBulletActive, bulletCount, stinkyX, stinkyY, score, theifX, theifY);
        boombieBulletDetectionwithMickey(boombieBulletX, boombieBulletY, isBoombieBulletActive, boomieBulletCount, mickeyX, mickeyY, mickeyHealth);
        theifBulletDetectionwithMickey(mickeyX, mickeyY, key, theifBulletX, theifBulletY, isTheifBulletActive, theifBulletCount);
        Sleep(100);
    }
}
string logo()
{

    header();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    string option;
    cout << "1.Display menu " << endl;
    cout << "2.Start Game " << endl;
    cout << "3.Resume Game " << endl;
    cout << "4.Exit " << endl
         << endl;
    cout << "Enter your choice: ";
    cin >> option;
    return option;
}

void printBoombie(int &boombieX, int &boombieY)
{
    char boombie[5][9] = {
        {' ', ' ', '_', '_', '_', '_', '_', ' ', ' '},
        {' ', '/', ' ', ' ', ' ', ' ', ' ', '\\', ' '},
        {'|', ' ', '(', ')', ' ', '(', ')', ' ', '|'},
        {' ', '\\', ' ', ' ', '^', ' ', ' ', '/'},
        {' ', ' ', '!', '!', '!', '!', '!'}};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int row = 0; row < 5; row++)
    {
        gotoxy(boombieX, boombieY + row);
        for (int col = 0; col < 9; col++)
        {
            cout << boombie[row][col];
        }
    }
}

void printTheif(int &theifX, int &theifY)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    char headT = 237;
    char hand = 236;
    char bodyT = 219;
    char feet = 202;
    char theif[3][4] = {
        {' ', ' ', headT, ' '},
        {hand, '<', bodyT, bodyT},
        {' ', ' ', feet, feet}};

    for (int row = 0; row < 3; row++)
    {
        gotoxy(theifX, theifY + row);
        for (int col = 0; col < 4; col++)
        {
            cout << theif[row][col];
        }
    }
}
void printMickey(int &mickeyX, int &mickeyY)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    char body = 178;
    char mickey[5][7] = {
        {'(', ')', '_', '_', '_', '(', ')'},
        {'(', 'o', ' ', '^', ' ', 'o', ')'},
        {' ', '(', ']', body, '[', ')', '}'},
        {' ', ' ', body, body, body, ' '},
        {' ', ' ', '@', ' ', '@'}};
    for (int row = 0; row < 5; row++)
    {
        gotoxy(mickeyX, mickeyY + row);
        for (int col = 0; col < 7; col++)
        {
            cout << mickey[row][col];
        }
    }
}
void eraseThief(int &theifX, int &theifY)
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(theifX, theifY + row);
        for (int col = 0; col < 4; col++)
        {
            cout << " ";
        }
    }
}
void eraseMickey(int &mickeyX, int &mickeyY)
{
    for (int row = 0; row < 5; row++)
    {
        gotoxy(mickeyX, mickeyY + row);
        for (int col = 0; col < 7; col++)
        {
            cout << " ";
        }
    }
}
void eraseBoombie(int &boombieX, int &boombieY)
{
    for (int row = 0; row <= 5; row++)
    {
        gotoxy(boombieX, boombieY + row);
        for (int col = 0; col < 9; col++)
        {
            cout << " ";
        }
    }
}
void eraseStinky(int &stinkyX, int &stinkyY)
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(stinkyX, stinkyY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}
void moveMickeyUp(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key)
{
    // checks all the coordinates in up direction
    char next = getCharAtxy(mickeyX, mickeyY - 1);
    char next1 = getCharAtxy(mickeyX + 1, mickeyY - 1);
    char next2 = getCharAtxy(mickeyX + 2, mickeyY - 1);
    char next3 = getCharAtxy(mickeyX + 3, mickeyY - 1);
    char next4 = getCharAtxy(mickeyX + 4, mickeyY - 1);
    char next5 = getCharAtxy(mickeyX + 5, mickeyY - 1);
    char next6 = getCharAtxy(mickeyX + 6, mickeyY - 1);

    if ((next == ' ' || next == 'k' || next == '%') && (next1 == ' ' || next1 == 'k' || next1 == '%') && (next2 == ' ' || next2 == 'k' || next2 == '%') && (next3 == ' ' || next3 == 'k' || next3 == '%') && (next4 == ' ' || next4 == 'k' || next4 == '%') && (next5 == ' ' || next5 == 'k' || next5 == '%') && (next6 == ' ' || next6 == 'k' || next6 == '%'))
    {
        eraseMickey(mickeyX, mickeyY);
        mickeyY = mickeyY - 1;
        printMickey(mickeyX, mickeyY);
    }
    if (next == 'k' || next1 == 'k' || next2 == 'k' || next3 == 'k' || next4 == 'k')
    {
        key = key + 1;
    }
    if (next == '%' || next1 == '%' || next2 == '%' || next3 == '%' || next4 == '%')
    {
        mickeyHealth = mickeyHealth + 10;
    }
}
void moveMickeyDown(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key)
{
    char next = getCharAtxy(mickeyX, mickeyY + 5);
    char next1 = getCharAtxy(mickeyX + 1, mickeyY + 5);
    char next2 = getCharAtxy(mickeyX + 2, mickeyY + 5);
    char next3 = getCharAtxy(mickeyX + 3, mickeyY + 5);
    char next4 = getCharAtxy(mickeyX + 4, mickeyY + 5);
    char next5 = getCharAtxy(mickeyX + 5, mickeyY + 5);
    char next6 = getCharAtxy(mickeyX + 6, mickeyY + 5);

    if ((next == ' ' || next == 'k' || next == '%') && (next1 == ' ' || next1 == 'k' || next1 == '%') && (next2 == ' ' || next2 == 'k' || next2 == '%') && (next3 == ' ' || next3 == 'k' || next3 == '%') && (next4 == ' ' || next4 == 'k' || next4 == '%') && (next5 == ' ' || next5 == 'k' || next5 == '%') && (next6 == ' ' || next6 == 'k' || next6 == '%'))
    {
        eraseMickey(mickeyX, mickeyY);
        mickeyY = mickeyY + 1;
        printMickey(mickeyX, mickeyY);
    }
    if (next == 'k' || next1 == 'k' || next2 == 'k' || next3 == 'k' || next4 == 'k')
    {
        key = key + 1;
    }
    if (next == '%' || next1 == '%' || next2 == '%' || next3 == '%' || next4 == '%')
    {
        mickeyHealth = mickeyHealth + 10;
    }
}
void moveMickeyLeft(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key)
{

    char next = getCharAtxy(mickeyX - 1, mickeyY);
    char next1 = getCharAtxy(mickeyX - 1, mickeyY + 1);
    char next2 = getCharAtxy(mickeyX - 1, mickeyY + 2);
    char next3 = getCharAtxy(mickeyX - 1, mickeyY + 3);
    char next4 = getCharAtxy(mickeyX - 1, mickeyY + 4);

    if ((next == ' ' || next == 'k' || next == '%') && (next1 == ' ' || next1 == 'k' || next1 == '%') && (next2 == ' ' || next2 == 'k' || next2 == '%') && (next3 == ' ' || next3 == 'k' || next3 == '%') && (next4 == ' ' || next4 == 'k' || next4 == '%'))
    {
        eraseMickey(mickeyX, mickeyY);
        mickeyX = mickeyX - 1;
        printMickey(mickeyX, mickeyY);
    }
    if (next == 'k' || next1 == 'k' || next2 == 'k' || next3 == 'k' || next4 == 'k')
    {
        key = key + 1;
    }
    if (next == '%' || next1 == '%' || next2 == '%' || next3 == '%' || next4 == '%')
    {
        mickeyHealth = mickeyHealth + 10;
    }
}
void moveMickeyRight(int &mickeyX, int &mickeyY, int &mickeyHealth, int &key)
{
    char next = getCharAtxy(mickeyX + 7, mickeyY);
    char next1 = getCharAtxy(mickeyX + 7, mickeyY + 1);
    char next2 = getCharAtxy(mickeyX + 7, mickeyY + 2);
    char next3 = getCharAtxy(mickeyX + 7, mickeyY + 3);
    char next4 = getCharAtxy(mickeyX + 7, mickeyY + 4);
    if ((next == ' ' || next == 'k' || next == '%') && (next1 == ' ' || next1 == 'k' || next1 == '%') && (next2 == ' ' || next2 == 'k' || next2 == '%') && (next3 == ' ' || next3 == 'k' || next3 == '%') && (next4 == ' ' || next4 == 'k' || next4 == '%'))
    {
        eraseMickey(mickeyX, mickeyY);
        mickeyX = mickeyX + 1;
        printMickey(mickeyX, mickeyY);
    }
    if (next == 'k' || next1 == 'k' || next2 == 'k' || next3 == 'k' || next4 == 'k')
    {
        key = key + 1;
    }
    if (next == '%' || next1 == '%' || next2 == '%' || next3 == '%' || next4 == '%')
    {
        mickeyHealth = mickeyHealth + 10;
    }
}
void moveStinky(int &stinkyX, int &stinkyY, string &stinkyDirection)
{
    if (stinkyDirection == "Up")
    {
        char next = getCharAtxy(stinkyX, stinkyY - 1);
        char next1 = getCharAtxy(stinkyX + 1, stinkyY - 1);
        char next2 = getCharAtxy(stinkyX + 2, stinkyY - 1);
        if (next == ' ' && next1 == ' ' && next2 == ' ')
        {
            eraseStinky(stinkyX, stinkyY);
            stinkyY--;
            printStinky(stinkyX, stinkyY);
        }
        if (next == '$')
        {
            stinkyDirection = "Down";
        }
    }
    if (stinkyDirection == "Down")
    {
        char next = getCharAtxy(stinkyX, stinkyY + 3);
        char next1 = getCharAtxy(stinkyX + 1, stinkyY + 3);
        char next2 = getCharAtxy(stinkyX + 2, stinkyY + 3);
        char next3 = getCharAtxy(stinkyX + 3, stinkyY + 3);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            eraseStinky(stinkyX, stinkyY);
            stinkyY++;
            printStinky(stinkyX, stinkyY);
        }
        if (next == '$')
        {
            stinkyDirection = "Up";
        }
    }
}
void moveBoombie(int &boombieX, int &boombieY, string &boombieDirection)
{

    if (boombieDirection == "Right")
    {
        char next = getCharAtxy(boombieX + 9, boombieY);
        char next1 = getCharAtxy(boombieX + 9, boombieY + 1);
        char next2 = getCharAtxy(boombieX + 9, boombieY + 2);
        char next3 = getCharAtxy(boombieX + 9, boombieY + 3);
        char next4 = getCharAtxy(boombieX + 9, boombieY + 4);

        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseBoombie(boombieX, boombieY);
            boombieX = boombieX + 1;
            printBoombie(boombieX, boombieY);
        }
        if (next == '!')
        {
            boombieDirection = "Left";
        }
    }
    if (boombieDirection == "Left")
    {
        char next = getCharAtxy(boombieX - 1, boombieY);
        char next1 = getCharAtxy(boombieX - 1, boombieY + 1);
        char next2 = getCharAtxy(boombieX - 1, boombieY + 2);
        char next3 = getCharAtxy(boombieX - 1, boombieY + 3);
        char next4 = getCharAtxy(boombieX - 1, boombieY + 4);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseBoombie(boombieX, boombieY);
            boombieX = boombieX - 1;
            printBoombie(boombieX, boombieY);
        }
        if (next == '!')
        {
            boombieDirection = "Right";
        }
    }
}
void moveTheif(int &theifX, int &theifY, int &theifDirection)
{
    if (theifDirection == 0)
    {
        // move up
        char next = getCharAtxy(theifX, theifY - 1);
        char next1 = getCharAtxy(theifX + 1, theifY - 1);
        char next2 = getCharAtxy(theifX + 2, theifY - 1);
        char next3 = getCharAtxy(theifX + 3, theifY - 1);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            eraseThief(theifX, theifY);
            theifY--;
            printTheif(theifX, theifY);
        }
        else
        {
            theifDirection = rand() % 4;
        }
    }
    if (theifDirection == 1)
    {
        // move down
        char next = getCharAtxy(theifX, theifY + 3);
        char next1 = getCharAtxy(theifX + 1, theifY + 3);
        char next2 = getCharAtxy(theifX + 2, theifY + 3);
        char next3 = getCharAtxy(theifX + 3, theifY + 3);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            eraseThief(theifX, theifY);
            theifY++;
            printTheif(theifX, theifY);
        }
        else
        {
            theifDirection = rand() % 4;
        }
    }
    if (theifDirection == 2)
    {
        // move left
        char next = getCharAtxy(theifX - 1, theifY);
        char next1 = getCharAtxy(theifX - 1, theifY + 1);
        char next2 = getCharAtxy(theifX - 1, theifY + 2);
        if (next == ' ' && next1 == ' ' && next2 == ' ')
        {
            eraseThief(theifX, theifY);
            theifX = theifX - 1;
            printTheif(theifX, theifY);
        }
        else
        {
            theifDirection = rand() % 4;
        }
    }
    if (theifDirection == 3)
    {
        // move right
        char next = getCharAtxy(theifX + 9, theifY);
        char next1 = getCharAtxy(theifX + 9, theifY + 1);
        char next2 = getCharAtxy(theifX + 9, theifY + 2);

        if (next == ' ' && next1 == ' ' && next2 == ' ')
        {
            eraseThief(theifX, theifY);
            theifX = theifX + 1;
            printTheif(theifX, theifY);
        }
        else
        {
            theifDirection = rand() % 4;
        }
    }
}

void createBullet(int &mickeyX, int &mickeyY, int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    mickBulletX[bulletCount] = mickeyX + 9;
    mickBulletY[bulletCount] = mickeyY + 2;
    isBulletActive[bulletCount] = true;
    gotoxy(mickeyX + 9, mickeyY + 2);
    cout << "-";
    bulletCount++;
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index, bool isBulletActive[])
{

    isBulletActive[index] = false;
}
void moveBullet(int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount)
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            char next = getCharAtxy(mickBulletX[i] + 1, mickBulletY[i]);
            if (next != ' ')
            {
                eraseBullet(mickBulletX[i], mickBulletY[i]);
                makeBulletInactive(i, isBulletActive);
            }
            else
            {
                eraseBullet(mickBulletX[i], mickBulletY[i]);
                mickBulletX[i]++;
                printBullet(mickBulletX[i], mickBulletY[i]);
            }
        }
    }
}
void createBoombieBullet(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount, int &boombieX, int &boombieY)
{
    boombieBulletX[boomieBulletCount] = boombieX + 5;
    boombieBulletY[boomieBulletCount] = boombieY + 6;
    isBoombieBulletActive[boomieBulletCount] = true;
    gotoxy(boombieX + 4, boombieY + 5);
    cout << "o";
    boomieBulletCount++;
}
void printBoombieBullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "o";
}
void eraseBoombieBullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBoombieBulletInactive(int index, bool isBoombieBulletActive[])
{

    isBoombieBulletActive[index] = false;
}
void moveBoombieBullet(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount)
{
    for (int i = 0; i < boomieBulletCount; i++)
    {
        if (isBoombieBulletActive[i] == true)
        {
            char next = getCharAtxy(boombieBulletX[i], boombieBulletY[i] + 1);
            if (next != ' ')
            {
                eraseBoombieBullet(boombieBulletX[i], boombieBulletY[i]);
                makeBoombieBulletInactive(i, isBoombieBulletActive);
            }
            else
            {
                eraseBoombieBullet(boombieBulletX[i], boombieBulletY[i]);
                boombieBulletY[i]++;
                printBoombieBullet(boombieBulletX[i], boombieBulletY[i]);
            }
        }
    }
}
void mickeyHeader()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(45, 5);
    cout << "      _                  _      " << endl;
    gotoxy(45, 6);
    cout << "   ,-@@@@@-.          .-@@@@@-. " << endl;
    gotoxy(45, 7);
    cout << " .\"@@@@@@@@@\\       /@@@@@@@@@\". " << endl;
    gotoxy(45, 8);
    cout << " :@@@@@@@@@@@ :      :@@@@@@@@@@@: " << endl;
    gotoxy(45, 9);
    cout << " :@@@@@@@@@@@@@.mmmm.'@@@@@@@@@@@: " << endl;
    gotoxy(45, 10);
    cout << " `\\@@@@@@@@,---###---.@@@@@@@@@.'" << endl;
    gotoxy(45, 11);
    cout << "    \"-.@@@,\"  __ v __   \".@@@@-\" " << endl;
    gotoxy(45, 12);
    cout << "       7@:   /  | |  \\  :@<    " << endl;
    gotoxy(45, 13);
    cout << "      ;@@:   :,-| |-.:  :@@\\    " << endl;
    gotoxy(45, 14);
    cout << "     :@@@\\    \\@|_|@/   /@@@:" << endl;
    gotoxy(45, 15);
    cout << "     :###.>  ',---.`  <,###:   " << endl;
    gotoxy(45, 16);
    cout << "     :    __ ( @@@ ) __    ;  " << endl;
    gotoxy(45, 17);
    cout << "      \".   \\  `---'  //   ,\"" << endl;
    gotoxy(45, 18);
    cout << "        \".  \\-------//  ,\" " << endl;
    gotoxy(45, 19);
    cout << "          \"._`.___,'_,\"  " << endl;
    gotoxy(45, 20);
    cout << "             \".___.\"" << endl;
}
void printScore(int &score)
{
    gotoxy(118, 2);
    cout << "Score: " << score;
}
void printMickeyHealth(int &mickeyHealth)
{
    gotoxy(118, 3);
    cout << "Mickey Health: " << mickeyHealth;
}
void printMickeyLife(int &mickeyLife)
{
    gotoxy(118, 4);
    cout << "Mickey Life: " << mickeyLife;
}
void printKeys(int &key)
{
    gotoxy(118, 5);
    cout << "Keys: " << key;
}
void mickBulletDetectionwithEnemies(int &boombieX, int &boombieY, int mickBulletX[], int mickBulletY[], bool isBulletActive[], int &bulletCount, int &stinkyX, int &stinkyY, int &score, int &theifX, int &theifY)
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            // check detection with stinky
            if (mickBulletX[x] + 1 == stinkyX && ((mickBulletY[x]) == stinkyY || mickBulletY[x] == stinkyY + 2))
            {
                score = score + 1;
                // stinkyHealth = stinkyHealth - 2;
            }
            if ((stinkyX - 1 == mickBulletX[x]) && (stinkyY + 1 == mickBulletY[x]))
            {
                score = score + 1;
            }
            // check detection with boombie
            if (mickBulletX[x] + 1 == boombieX && ((mickBulletY[x]) == boombieY || mickBulletY[x] == boombieY + 1 || mickBulletY[x] == boombieY + 3 || mickBulletY[x] == boombieY + 4))
            {
                score = score + 5;
            }
            if ((boombieX - 1 == mickBulletX[x]) && (boombieY + 2 == mickBulletY[x]))
            {
                score = score + 5;
            }
            // check detection with theif
            if (mickBulletX[x] + 1 == theifX && ((mickBulletY[x]) == theifY || mickBulletY[x] == theifY + 2))
            {
                score = score + 2;
            }
            if ((theifY - 1 == mickBulletX[x]) && (theifY + 1 == mickBulletY[x]))
            {
                score = score + 2;
            }
        }
    }
}
void boombieBulletDetectionwithMickey(int boombieBulletX[], int boombieBulletY[], bool isBoombieBulletActive[], int &boomieBulletCount, int &mickeyX, int &mickeyY, int &mickeyHealth)
{
    for (int x = 0; x < boomieBulletCount; x++)
    {
        if (isBoombieBulletActive[x] == true)
        {
            if (boombieBulletY[x] + 1 == mickeyY && ((boombieBulletX[x]) == mickeyX || boombieBulletX[x] == mickeyX + 1 || boombieBulletX[x] == mickeyX + 3 || boombieBulletX[x] == mickeyX + 4 || boombieBulletX[x] == mickeyX + 5))
            {
                mickeyHealth = mickeyHealth - 5;
            }
        }
    }
}
void createStinkyBullet(int &stinkyX, int &stinkyY, bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount)
{

    stinkyBulletX[stinkyBulletCount] = stinkyX - 1;
    stinkyBulletY[stinkyBulletCount] = stinkyY + 1;
    isStinkyBulletActive[stinkyBulletCount] = true;
    gotoxy(stinkyX - 1, stinkyY + 1);
    cout << "*";
    stinkyBulletCount++;
}
void printStinkyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseStinkyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeStinkyBulletInactive(int index, bool isStinkyBulletActive[])
{
    isStinkyBulletActive[index] = false;
}
void moveStinkyBullet(bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount)
{
    for (int i = 0; i < stinkyBulletCount; i++)
    {
        if (isStinkyBulletActive[i] == true)
        {
            char next = getCharAtxy(stinkyBulletX[i] - 1, stinkyBulletY[i]);
            if (next != ' ')
            {
                eraseStinkyBullet(stinkyBulletX[i], stinkyBulletY[i]);
                makeStinkyBulletInactive(i, isStinkyBulletActive);
            }
            else
            {
                eraseStinkyBullet(stinkyBulletX[i], stinkyBulletY[i]);
                stinkyBulletX[i]--;
                printStinkyBullet(stinkyBulletX[i], stinkyBulletY[i]);
            }
        }
    }
}

void StinkyBulletDetectionwithMickey(int &mickeyX, int &mickeyY, int &mickeyHealth, bool isStinkyBulletActive[], int stinkyBulletX[], int stinkyBulletY[], int &stinkyBulletCount)
{
    for (int x = 0; x < stinkyBulletCount; x++)
    {
        if (isStinkyBulletActive[x] == true)
        {
            if (stinkyBulletX[x] - 1 >= mickeyX && stinkyBulletX[x] - 1 <= mickeyX + 6 && stinkyBulletY[x] >= mickeyY && stinkyBulletY[x] <= mickeyY + 4)
            {
                mickeyHealth = mickeyHealth - 2;
            }
        }
    }
}

void createTheifBullet(int &theifX, int &theifY, int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount)
{
    char left = getCharAtxy(theifX - 1, theifY + 1);
    if (left != '!')
    {
        theifBulletX[theifBulletCount] = theifX - 1;
        theifBulletY[theifBulletCount] = theifY + 1;
        isTheifBulletActive[theifBulletCount] = true;
        gotoxy(theifX - 1, theifY + 1);
        cout << ".";
        theifBulletCount++;
    }
}

void printTheifBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseTheifBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeTheifBulletInactive(int index, bool isTheifBulletActive[])
{
    isTheifBulletActive[index] = false;
}

void moveTheifBullet(int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount)
{
    for (int i = 0; i < theifBulletCount; i++)
    {
        if (isTheifBulletActive[i] == true)
        {
            char next = getCharAtxy(theifBulletX[i] - 1, theifBulletY[i]);
            if (next != ' ')
            {
                eraseTheifBullet(theifBulletX[i], theifBulletY[i]);
                makeTheifBulletInactive(i, isTheifBulletActive);
            }
            else
            {
                eraseTheifBullet(theifBulletX[i], theifBulletY[i]);
                theifBulletX[i]--;
                printTheifBullet(theifBulletX[i], theifBulletY[i]);
            }
        }
    }
}

void theifBulletDetectionwithMickey(int &mickeyX, int &mickeyY, int &key, int theifBulletX[], int theifBulletY[], bool isTheifBulletActive[], int &theifBulletCount)
{
    for (int x = 0; x < theifBulletCount; x++)
    {
        if (isTheifBulletActive[x] == true)
        {
            if (theifBulletX[x] - 1 >= mickeyX && theifBulletX[x] - 1 <= mickeyX + 6 && theifBulletY[x] >= mickeyY && theifBulletY[x] <= mickeyY + 4)
            {
                key = key - 1;
            }
        }
    }
}

void loadDataFromMazeFile()
{

    fstream myFile;
    myFile.open("maze.txt", ios::in);
    string line;
    int row = 0;
    while (getline(myFile, line))
    {
        for (int index = 0; index < line.length(); index++)
        {
            maze[row][index] = line[index];
        }
        row++;
    }
    myFile.close();
}
void storeDataToResumeFile()
{

    fstream myFile;
    myFile.open("resume.txt", ios::out);
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 116; j++)
        {
            myFile << maze[i][j];
        }
        myFile << endl;
    }
    myFile.close();
}

void printMaze(string arr[][116], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}