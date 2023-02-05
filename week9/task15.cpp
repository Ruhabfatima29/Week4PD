#include<iostream>
using namespace std;
main()
{
int arraySize;
cout << "Enter array size: ";
cin >> arraySize;
int numbers[arraySize];
for(int index=0; index<arraySize; index++)
{
cout << " Enter number: ";
cin >> numbers[index];
}
int largest= numbers[0];
for (int index=0; index< arraySize; index++)
{
    if(numbers[index]>numbers[0])
    {
        largest = numbers[index];
    }

}
cout << "The greatest number is " << largest;

}