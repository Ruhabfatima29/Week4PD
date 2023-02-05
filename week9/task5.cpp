#include<iostream>
using namespace std;
main()
{
int size, number;
cout << "ENTER SIZE OF ARRAY: ";
cin >> size;
int numbers[size];
for (int idx=0; idx<size; idx++)
{
    cout << "Enter number: ";
    cin >> numbers[idx];
}
cout << "Enter the scalar value: ";
cin >> number;
for (int idx=size-1; idx>=0; idx--)
{
    cout << number*numbers[idx] << " ";
}
}