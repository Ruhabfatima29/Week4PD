#include<iostream>
using namespace std;
main()
{
int size;
cout << "Enter array size: ";
cin >> size;
int number[size];
for(int idx=0; idx<size; idx++)
{
    cout << "Enter value: ";
    cin  >> number[idx];
}
for(int idx=size-1; idx>=0; idx--)
{
cout << number << " ";
}

}