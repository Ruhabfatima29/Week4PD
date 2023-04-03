#include <iostream>
using namespace std;
// Function prototype
int checkCondition(int size);
// Global array
int marathon[20];
// Funtion definition
main()
{

    int size;
    int result;
    cout << " Enter how many weeks did you run: ";
    cin >> size;
    result = checkCondition(size);
    cout << result << " Progress Days." << endl;
}
int checkCondition(int size)
{
    int count = 0;
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter no. of miles: ";
        cin >> marathon[idx];
    }
    for (int idx = 0; idx < size - 1; idx++)
    {
        int previous = marathon[idx];
        int current = marathon[idx + 1];
        if (current > previous)
        {
            count++;
        }
    }
    return count;
}