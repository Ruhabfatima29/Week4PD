#include<iostream>
using namespace std;
main()
{
int arr_size;
cout << "Enter the size of array: ";
cin  >> arr_size;
float cgpa[arr_size];
for(int index=0; index<arr_size; index++)
{
cout << "Enter value: ";
cin >> cgpa[index];
}
for(int index=0; index<arr_size; index++)
{
cout  << cgpa[index] << " ";
}
}