#include <iostream>
using namespace std;
void pattern(int rowNo);
main()
{
    int row;
    cout << "Enter the desired no. of rows : ";
    cin >> row;
    pattern(row);
}
void pattern(int row)
{
    for (int i = 1; i <= row+1; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j >= i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        for (int j = row; j >= 1; j--)
        {
            if (i > row)
            {
                cout << "*";
            }
            else if (j >= i)
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