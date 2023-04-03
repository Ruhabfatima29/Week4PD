#include <iostream>
#include <conio.h>
using namespace std;
int checkRows();
bool checkRow(int row , int nextRow);
int numberArrays[4][3] = {{0, 0, 0}, {0, 1, 2}, {0, 0, 0}, {2, 1, 0}};
main()
{
    int total;
    total = checkRows();
    cout << "Similar rows are " << total;
}
bool checkRow(int row , int nextRow)
{

    for (int col = 0; col < 3; col++)
    {
        if (numberArrays[row][col] != numberArrays[nextRow][col])
        {
            return false;
        }
    }
   return true;
}
int checkRows()
{
    int count=0;
    for (int row=0; row<4; row++)
    {
        if(checkRow(row,row+1) ||checkRow(row,row+2) || checkRow(row,row+3) )
        {
            count++;
        }
    }
    return count;
}