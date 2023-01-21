#include <iostream>
using namespace std;
void upperPart(int rowNo);
void lowerPart(int row);
main()
{
    int row;
    cout << "Enter the desired no. of rows : ";
    cin >> row;
    upperPart(row);
    lowerPart(row);
}
void upperPart(int row)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j > row - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void lowerPart(int row)
{
   for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j <= i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    
}