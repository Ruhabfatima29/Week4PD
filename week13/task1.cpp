#include <iostream>
#include <conio.h>
using namespace std;
bool identityMatrix();
int matrix[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
};
main()
{
    bool check = identityMatrix();
    if (check == true)
    {
        cout << "Identity Matrix";
    }
    else
    {
        cout << "NOt an Identity Matrix";
    }
}
bool identityMatrix()
{
    int count1 = 0;
    int count0 = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row == col && matrix[row][col] == 1)
            {
                count1++;
            }
            if (row != col && matrix[row][col] == 0)
            {
                count0++;
            }
        }
    }
    if (count1 == 3 && count0 == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}