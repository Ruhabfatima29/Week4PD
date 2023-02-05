#include<iostream>
using namespace std;
main()
{
int arraySize;
cout << "Enter array size: ";
cin >> arraySize;
int numbers[arraySize];
int number;
for(int index=0; index<arraySize; index++)
{
cout << " Enter number: ";
cin >> numbers[index];
}
cout << "Enter number to find: ";
cin >> number;
for(int index=0; index<arraySize; index++)
{
   if( numbers[index]== number)
   {
    cout << "Already Found ";
   }

}
}
