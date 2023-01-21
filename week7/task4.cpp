#include<iostream>
using namespace std;
int frequencyChecker(int number, int check);
main()
{
    int number , check ;
    cout << "Enter any number : ";
    cin  >> number;
    cout << "Enter the no. whose frequency you want to check : ";
    cin  >> check;
    frequencyChecker(number, check);
}
int frequencyChecker(int number, int check)
{ 
    int result , count = 0 ;
    while(number>0)
    {
    result = number % 10;
    if (result == check)
    {
    count = count +1;
    }
    number = number/10;

    }
    cout << count ;
}










