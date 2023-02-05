#include <iostream>
using namespace std;
main()
{
    int size = 4;
    string word[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter statement: ";
        cin >> word[idx];
    }
    bool check;
    for (int idx = 0; idx < size; idx++)
    {
        if (word[idx] == word[0])
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    if (check == true)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}
