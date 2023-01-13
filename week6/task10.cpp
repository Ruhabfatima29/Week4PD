#include<iostream>
using namespace std;
bool greaterNumber(int,int,int);
main()
{
int number1,number2, number3;
bool result;
string output;
cout << "Enter number1:" ;
cin  >> number1;
cout << "Enter number2:" ;
cin  >> number2;
cout << "Enter number3:" ;
cin  >> number3;
result = greaterNumber(number1,number2,number3);
if (result == true)
{
    output = "yes"; 
}
if (result == false)
{
    output = "no"; 
}
cout << output ;
}
bool greaterNumber(int number1,int number2 ,int number3)
{
if(number1==2&&number2==3)
{
return true;
}
else 
{
return false;
}

}