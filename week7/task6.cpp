#include<iostream>
using namespace std;
int calculateGCD(int number1, int);
int calculateLCM(int, int ,int);
main()
{
int number1, number2 , GCD, LCM;
cout << "Enter number1: ";
cin >> number1;
cout << "Enter number2: ";
cin  >> number2;
GCD = calculateGCD(number1, number2);
cout << "HCF is "<< GCD << endl;
LCM = calculateLCM(number1,number2,GCD);
cout << "LCM is " << LCM;
}
int calculateGCD(int number1, int number2)
{
int result1 , output , result2;
int smaller = min(number1,number2);
for(int count = smaller ; count >= 0 ; count--)
{
result1 = (number1 % count) ;
result2 = (number2 % count) ;
if (result1 == 0 && result2 == 0 )
{
output = count ;
return output;
}
}
}
int calculateLCM( int number1, int number2, int GCD)
{
int lcm;
lcm = (number1*number2)/GCD;
return lcm;
}
