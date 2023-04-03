#include <iostream>
#include <conio.h>

using namespace std;

const int gridSize = 3;
char board[gridSize][gridSize] = {{'#', '#', '#'},
                                  {'#', '#', '#'},
                                  {'#', '#', '#'}};
string checkValidity(int row, int col);
void printBoard();
void updateGrid(int row, int col, char symbol);
bool isWinner(char symbol);
bool isTie();

int main()
{
    int row, col;
    string input;
    char player1Symbol = 'X';
    char player2Symbol = 'O';
    char currentPlayer = player1Symbol;

    printBoard();

    while (!isWinner(player1Symbol) && !isWinner(player2Symbol) && !isTie())
    {
        // Get input from the current player
        cout << "Player " << currentPlayer << ", enter row and column (e.g. 1a): ";
        getline(cin, input);
        // Parse row and column from input
        row = input[0] - '0';
        col = input[1] - 'a';
        if(checkValidity(row,col) == "yes")
        {
        // Update the grid
        updateGrid(row, col, currentPlayer);
         
        // Print the updated board
        printBoard();

        // Switch to the other player
        if (currentPlayer == player1Symbol)
        {
            currentPlayer = player2Symbol;
        }
        else
        {
            currentPlayer = player1Symbol;
        }
        }
        else
        {
           cout << checkValidity(row,col) << "Choose another location" << endl;
        }
    }

    // Game over, print the result
    if (isTie())
    {
        cout << "It's a tie!" << endl;
    }
    else
    {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }

    return 0;
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
        cout << row + 1 << "       ";
        for (int col = 0; col < 3; col++)
        {
            cout << board[row][col] << "\t";
        }
        cout << endl;
    }
}

void updateGrid(int row, int col, char symbol)
{
    board[row - 1][col] = symbol;
}
string checkValidity(int row, int col)
{
    if(board[row - 1][col] == 'X' || board[row - 1][col]== 'O')
    {
        return "Already taken";
    }
    return "yes";
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

bool isTie()
{
    bool check = true;
    for (int row = 0; row < gridSize; row++)
    {
        for (int col = 0; col < gridSize; col++)
        {
            if (board[row][col] == '#')
            {
                check = false;
            }
        }
    }
    return check;
}