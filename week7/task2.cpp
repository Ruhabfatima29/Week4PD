#include<iostream>
using namespace std;
main()
{
    int length;
    cout << "Enter the length of fibonacci series : ";
    cin  >> length;
    int number1 = 0 , number2 = 1;
    cout << number1 << "," << number2 ;  
    for(int count = 1, result; count <=length-2;  count++ )
    {
     result = number1 + number2;
     cout << "," << result;
     number1 = number2;
     number2 = result;

    }
}