#include<iostream>
using namespace std;
main()
{
int number[2];
int arraySize;
cout << "Enter array size: ";
cin >> arraySize;
int numbers[arraySize];
for(int index=0; index<2; index++)
{
    cout << "Enter number for first array: ";
    cin >> number[index];
}
for(int index=0; index<arraySize; index++)
{
    cout << "Enter number: ";
    cin >> numbers[index];
}
cout << number[0] << " ";
for(int index=0; index<arraySize; index++)
{
    cout << numbers[index] << " ";
}
cout << number[1] << " ";

}