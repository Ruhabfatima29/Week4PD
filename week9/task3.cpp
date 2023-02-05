#include <iostream>
using namespace std;
main()
{
int number;
int size;
string check = "Absent";
cout << "Enter array size: ";
cin >> size;
int num[size];
for (int index=0; index<size; index++)
{
cout << "Enter value: ";
cin >> num[index];
}
cout << "Enter the number you want to find: ";
cin >> number;
for (int index=0; index<size; index++)
{
   if (number == num[index])
   {
   check = "PRESENT";
   }

}
cout << check;

}