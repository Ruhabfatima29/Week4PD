#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int add( int number1, int number2);
float divide (float number1,float number2);
int isGreater(int number1, int number2);
main()
{
  int number1, number2, total , greater;
  float result;
  cout << " Enter any no: ";
  cin  >> number1;
  cout << " Enter any no: ";
  cin  >> number2;
  total =add(number1, number2);
  cout << " The total sum is " << total << endl;
  result = divide (number1 , number2);
  cout << " The division is " << result << endl ;
  greater = isGreater(number1,number2);
  cout << " The greater no. is " << greater << endl;  
  cout << " Program ends. " ;
}
int add (int number1, int number2)
{ 
  int sum = number1 + number2;
  return sum;

}
float divide (float number1,float number2)
{
 float divide = number1 / number2;
 return divide;
}
int isGreater(int number1, int number2)
{
   if(number1 > number2)
   {
    return number1;

   }
   if(number2 > number1)
   {
    return number2;
   }
   return0 ;
}


