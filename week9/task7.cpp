#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int count = 0;
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    for (int index = 0; name[index] != '\0'; index++)
    {
        count++;
    }
    cout << "NUmber of characters is " << count;
}