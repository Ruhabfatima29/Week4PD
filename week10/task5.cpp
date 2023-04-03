#include<iostream>
using namespace std;

main()
{
    int sum =0;
int size;
cout << "Enter how many boxes you want to input: ";
cin >> size;
int length = size*3;
int numbers[length];
for (int idx=0; idx<length; idx++)
{
    cout << "Enter number: ";
    cin >> numbers[idx] ;
}
// to calculate volume
for (int idx=0; idx<length; idx=idx+3)
{
sum = sum + (numbers[idx]* numbers[idx+1]* numbers[idx+2]);
}
  cout << "Total volume of boxes is " << sum ;  
}