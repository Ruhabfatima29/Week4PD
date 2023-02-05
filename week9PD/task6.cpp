#include <iostream>
using namespace std;
main()
{
    int numbers[3];
    int times;
    for (int idx = 0; idx < 3; idx++)
    {
        cout << "Enter array elements: ";
        cin >> numbers[idx];
    }
    cout << "Enter number of times even odd transformation to be done: ";
    cin >> times;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int i = 1; i <= times; i++)
        {
            if (numbers[idx] % 2 == 0)
            {
                numbers[idx] = numbers[idx] - 2;
            }
            else
            {
                numbers[idx] = numbers[idx] + 2;
            }
        }
    }
    for (int idx = 0; idx < 3; idx++)
    {
        cout << numbers[idx] << " ";
    }
}