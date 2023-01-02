#include<iostream>
using namespace std;
void add(int number1, int number2) ;
void product(int number1, int number2);
void subtract(int number1, int number2);
void division(float number1, float number2);
main()
{ 
 int number1;
 int number2;
 char operation;
 while(true)
 {
 cout << " Enter 1st no. : "  ;
 cin  >> number1;
 cout << " Enter 2nd no. : "  ;
 cin >> number2;
 cout << " Enter any operator(+,-,*,/): " ;
 cin >> operation;
 if (operation == '+')
 {
 add(number1, number2);
 }
 if (operation == '*')
 {
 product(number1,number2);
 }
 if(operation == '-')
 {
 subtract(number1,number2);
 }
 if(operation == '/')
 {
  division(number1, number2);
 }
 }
}
void add(int number1, int number2)
{
  int sum;
  sum = number1 + number2;
  cout << " THE SUM IS  " << sum << endl;
}
void product(int number1, int number2)
{
  int product;
  product = number1 * number2 ;
  cout << " The product is " << product << endl ;
}
void subtract(int number1, int number2)
{
  int subtract;
  subtract = number1 - number2 ;
  cout << " The subtraction is " << subtract << endl ;
}
void division(float number1,float number2)
{
  float division;
  division = number1 / number2;
  cout << " The division is " << division << endl;
}