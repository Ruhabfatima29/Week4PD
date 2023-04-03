#include <iostream>
using namespace std;
int numbers[20];
bool checkCondition(int length);

main()
{
    bool result;
    int length;
    int number1;
    int number2;
    cout << "Enter length of cycle: ";
    cin >> length;
    result = checkCondition(length);
    if (result == true)
    {
      cout << "true";
    }
    else
    {
           cout << "false" ;   
    }
}
bool checkCondition(int length)
{
    bool result;
    int compare[length];
    int count = 0;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    for (int index = 0; index < size; index++)
    {
        cout << "Enter number: ";
        cin >> numbers[index];
    }
    for (int i = 0; i < length; i++)
    {

        compare[i] = numbers[i];
    }
    for (int i = 0; i < length; i++)
    {
        if (compare[i] == numbers[length + i])
        {
            count++;
        }
    }
    if (count == length || length > size)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}