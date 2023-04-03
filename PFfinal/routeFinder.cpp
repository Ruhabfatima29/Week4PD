#include <iostream>
#include <windows.h>
using namespace std;

const int rows = 3; // number of rows in the parking lot
const int cols = 5; // number of columns in the parking lot
void parkingExit(int arr[rows][cols]);
void printMovement(int dir, int steps);
bool findin2d(int arr[rows][cols], int val, int &row, int &col);
bool findInRow(int arr[cols], int val, int &col);

int main()
{
    int parking[rows][cols] = {
        {1, 0, 0, 0, 2},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << parking[i][j] << " ";
        }
        cout << endl;
    }
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "Quickest route to exit:" << endl;
    parkingExit(parking);

    return 0;
}

// Helper function to find the position of the stairs or exit
bool findInRow(int row[cols], int value, int &col)
{
    for (int j = 0; j < cols; j++)
    {
        if (row[j] == value)
        {
            col = j;
            return true;
        }
    }
    return false;
}

// Helper function to find the starting position
bool findin2d(int arr[rows][cols], int value, int &row, int &col)
{
    for (int i = 0; i < rows; i++)
    {
        if (findInRow(arr[i], value, col))
        {
            row = i;
            return true;
        }
    }
    return false;
}

// Helper function to print the movement (Left, Right, Down)
void printMovement(int dir, int steps)
{
    static int curr_dir = -1; // initialize current direction to 0 (undefined)
    if (dir != curr_dir)     // if new direction is different from current direction, print it
    {
        if (dir == 0)
        {
            cout << "Left: ";
        }
        else if (dir == 1)
        {
            cout << "Right: ";
        }
        else if (dir == 2)
        {
            cout << "Down: ";
        }
        curr_dir = dir;
    }
    cout << steps << "\n" ;
}

void parkingExit(int arr[rows][cols])
{
    int stairs[2][2];                             // position of the two staircases
    int start_row, start_col;                     // starting position
    int dest_row = rows - 1, dest_col = cols - 1; // destination position (bottom right)
    int curr_row, curr_col;                       // current position
    bool found = false;                           // flag to check if starting position and staircases are found
    // Find the positions of the staircases and the starting position
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                stairs[0][0] = i;
                stairs[0][1] = j;
            }
            else if (arr[i][j] == 2)
            {
                start_row = i;
                start_col = j;
                found = true;
            }
        }
        if (found)
        {
            break;
        }
    }
    stairs[1][0] = dest_row;
    stairs[1][1] = dest_col - 1;
    curr_row = start_row;
    curr_col = start_col;
    int curr_dir = 0; // initialize current direction to 0 (undefined)
    // Move to the first staircase (go left or right depending on the position)
    if (start_col < stairs[0][1])
    {
        printMovement(1, stairs[0][1] - start_col);
        curr_col = stairs[0][1];
        curr_dir = 1;
    }
    else if (start_col > stairs[0][1])
    {
        printMovement(0, start_col - stairs[0][1]);
        curr_col = stairs[0][1];
        curr_dir = 0;
    }
    // Move down the staircase
    printMovement(2, 1);
    curr_row++;
    curr_dir = 2;
    // Move to the second staircase (go left or right depending on the position)
    if (curr_col < stairs[1][1])
    {
        printMovement(1, stairs[1][1] - curr_col);
        curr_col = stairs[1][1];
        curr_dir = 1;
    }
    else if (curr_col > stairs[1][1])
    {
        printMovement(0, curr_col - stairs[1][1]);
        curr_col = stairs[1][1];
        curr_dir = 0;
    }
    // Move down to the exit
    printMovement(2, dest_row - curr_row);
}
