#include <iostream>
#include <conio.h>
using namespace std;
string checkBattleship(string coordinate);
char game[5][5] = {
    {'.', '.', '.', '*', '*'},
    {'.', '*', '.', ',', ','},
    {'.', '*', '.', '.', '.'},
    {'.', '*', '.', '.', '.'},
    {'.', '.', '*', '*', '.'}};
main()
{
    string coordinate;
    string result;
    cout << "Enter the coordinates: ";
    cin >> coordinate;
    result = checkBattleship(coordinate);
    cout << result;
}
string checkBattleship(string coordinate)
{
    char row = coordinate[0];
    char column = coordinate[1];
    int columnIndex = int(column) - '0';
    int rowIndex;
    if (row == 'A')
    {
        rowIndex = 0;
    }
    else if (row == 'B')
    {
        rowIndex = 1;
    }
    else if (row == 'C')
    {
        rowIndex = 2;
    }
    else if (row == 'D')
    {
        rowIndex = 3;
    }
    else if (row == 'E')
    {
        rowIndex = 4;
    }
    if (game[rowIndex][columnIndex] == '.')
    {
        return "Splash";
    }
    else if (game[rowIndex][columnIndex] == '*')
    {
        return "Boom";
    }
}
