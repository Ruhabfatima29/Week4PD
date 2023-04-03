#include <iostream>
using namespace std;
bool isSparse(int arr[][3], int size);
main()
{
    int matrix[][3] = {
        {1, 0, 3},
        {0, 0, 0},
        {9, 0, 4}};
    int rowSize = 3;
    bool check = isSparse(matrix, rowSize);
    cout << check;
}
bool isSparse(int arr[][3], int size)
{
    bool flag;
    int count = 0;
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (arr[row][col] == 0)
            {
                count++;
            }
        }
    }
    if (count > ((3 * 3) / 2))
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}