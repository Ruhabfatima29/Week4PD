#include<iostream>
using namespace std;
int totalDigit(int);
main()
{
int number;
cout << "Enter any number: ";
cin  >> number;
totalDigit(number);
}
int totalDigit(int number)
{
int count = 0;
while(number > 0)
{
number = number/10; 
count = count + 1;
}
cout << count ;

}