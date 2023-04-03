#include <iostream>
using namespace std;
int weights[10];
const int arraySize = sizeof(weights) / sizeof(weights[0]);
int smallest();
main()
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        cout << "Enter number: ";
        cin >> weights[idx];
    }
    int final_arr[arraySize];
    for (int idx = 0; idx < arraySize; idx++)
    {
        final_arr[idx] = smallest();
    }
    for (int i = 0; i < arraySize; i++)
    {
        cout << final_arr[i] << " , ";
    }
}
int smallest()
{
    int smallest = ' ';
    int index_count;
    for (int idx = 0; idx < arraySize; idx++)
    {
        int number = weights[idx];
        for (int idx = 0; idx < arraySize; idx++)
        {
            if (number > weights[idx])
            {
                smallest = weights[idx];
                index_count = idx;
            }
        }
    }
    weights[index_count] = ' ';
    return smallest;
}