#include <iostream>
#include <fstream>
#include <conio.h>
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
bool isWinner(char symbol);
void printBoard();
void updateGrid(string choice);
using namespace std;
const int gridSize = 3;
char board[gridSize][gridSize] = {{'$', '$', '$'},
                                  {'$', '$', '$'},
                                  {'$', '$', '$'}};
main()
{
    string choice;
    printBoard();
    while(isWinner == false)
    {
     cout << "Player1: enter where you want to mark: ";
     cin  >> choice;
    }
}
bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < gridSize; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < gridSize; col = col + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < gridSize; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < gridSize; row = row + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < gridSize; idx = idx + 1)
    {
        if (board[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < gridSize; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    return 0;
}
bool isWinner(char symbol)
{
    if (checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printBoard()
{
    cout << "\t"
         << "a"
         << "\t"
         << "b"
         << "\t"
         << "c" << endl;
    for (int row = 0; row < 3; row++)
    {
        cout << row << "       ";
        for (int col = 0; col < 3; col++)
        {
            cout << board[row][col] << "\t";
        }
        cout << endl;
    }
}
void updateGrid(string choice)
{
    char row = choice[1];
    char col = choice[0];
    int rowIndex = int(row) - '0';
    int colIndex;
    if (col == 'a')
    {
        colIndex = 0;
    }
    else if (col == 'b')
    {
        colIndex = 1;
    }
    else if (col == 'c')
    {
        colIndex = 2;
    }
   for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if(row == rowIndex && col == colIndex)
            {
            board[row][col] = 'O';
            }
        }
    }
}