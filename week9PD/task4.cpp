#include <iostream>
using namespace std;
main()
{
    int arr_size;
    cout << "Enter Array size: ";
    cin >> arr_size;
    int numbers[arr_size];
    for (int index = 0; index < arr_size; index++)
    {
        cout << "Enter numbers: ";
        cin >> numbers[index];
    }
    bool check = false;
    for (int index = 0; index < arr_size; index++)
    {
        int number = numbers[index];
        while (number > 0)
        {
            int remain = number % 10;
            if (remain == 7)
            {
                check = true;
            }

            number = number / 10;
        }
    }
    if (check == true)
    {
        cout << "Boom!";
    }
    else
    {
        cout << "there is no 7 in array";
    }
}