#include <iostream>
using namespace std;
main()
{
    int sum = 0;
    int arr_size;
    cout << "Enter how many numbers you want to sum: ";
    cin >> arr_size;
    float num[arr_size];
    for (int idx = 0; idx < arr_size; idx++)
    {
        cout << "Enter number: ";
        cin >> num[idx];
        sum = sum + num[idx];
    }
    cout << "Average is " <<sum/arr_size << endl;
    cout << "SUM of numbers is " << sum;
}