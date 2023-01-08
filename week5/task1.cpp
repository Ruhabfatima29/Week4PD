#include<iostream>
using namespace std;
int add( int number1, int number2);
main()
{
  int number1 , number2 ;
  int total;
  cout << " Enter number1: ";
  cin  >> number1;
  cout << " Enter number2: ";
  cin  >> number2;
  total = add( number1 , number2); 
  cout << " Sum is " << total << endl ;

}
int add( int number1, int number2)
{
  int sum;
  sum = number1 + number2;
  return sum;
}