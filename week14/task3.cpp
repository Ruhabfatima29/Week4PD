#include<iostream>
using namespace std;
float averageOfNumbers(int numbers[], int size);

main()
{
    int size;
    cout << "Enter the array of size: ";
    cin >> size;
    int numbers[size];
    float result;
    for(int idx=0; idx<size; idx++)
    {
        cout << " Enter number: ";
        cin >> numbers[idx];
    }
    result = averageOfNumbers(numbers,size);
    cout << "Average of numbers is " << result;
}
float averageOfNumbers(int numbers[], int size)
{
 int sum=0;
  for(int idx=0; idx<size; idx++)
    {
        sum = sum + numbers[idx];
    }
    return sum/size;
}