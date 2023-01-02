#include<iostream>
using namespace std;
main ()
{
int number;
int result,a,b,c,d ;
cout << " Enter four digit number : ";
cin  >> number;
a = number%10;
b = (number/10) % 10;
c = (number/100) %10;
d = (number/1000);
result = a+b+c+d;
cout << "The sum of the individual digit is ";
cout << result;

}
