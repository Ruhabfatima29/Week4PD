#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int smallest;
    int size;
    cout << "Enter size: ";
    cin >> size;
    int numbers[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> numbers[idx];
    }
    for (int idx = 0; idx < size; idx++)
    {
        smallest = min(numbers[0], numbers[idx]);
    }
    cout << "Smallest number is " << smallest;
}