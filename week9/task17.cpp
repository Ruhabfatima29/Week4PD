#include<iostream>
using namespace std;
main()
{
float due;
float sum; 
float  numbers[4];
for(int index=0; index<4; index++)
{
    cout << " Enter amount: ";
    cin >> numbers[index];
}
for(int index=0; index<4; index++)
{
    sum = (numbers[0]*0.25)+ (numbers[1]*0.10)+(numbers[2]*0.05)+(numbers[3]*0.01);
}
cout << "Enter due : ";
cin >> due;
if(sum>=due)
{
    cout << "True";
}
else
{
    cout << "False";
}
}