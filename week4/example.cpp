#include<iostream>
using namespace std;
void add(int number1, int number2) ;
void product(int number1, int number2);
main()
{ 
 int number1;
 int number2;
 cout << " Enter 1st no. : " ;
 cin  >> number1;
 cout << " Enter 2nd no. : " ;
 cin >> number2;
 add(number1, number2);
 product(number1,number2);

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