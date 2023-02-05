#include <iostream>
using namespace std;
main()
{
    float sum;
    int arr_size;
    cout << "Enter array size: ";
    cin >> arr_size;
    float resistance[arr_size];
    for (int index = 0; index < arr_size; index++)
    {
        cout << "Enter resistance: ";
        cin >> resistance[index];
        sum = sum + resistance[index];
    }
    cout << "Equivalent resistance in series is " << sum << "ohm";
}