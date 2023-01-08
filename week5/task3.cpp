#include<iostream>
#include<cmath>
using namespace std;
bool isSymmetrical(int number);
main()
{
 int number;
 bool result;
 cout << " Enter any 3-digit number : ";
 cin  >> number;
 result = isSymmetrical(number);
 if(result == true)
 {
  cout << " The number is symmetrical" << endl;
 }
 if(result == false)
 {
  cout << " The number is not symmetrical" << endl;
 }

}
bool isSymmetrical(int number)
{
 int a, b, c;
 a = number % 10;
 b = (number/10) % 10;
 c = number/100;
 if( a==c)
 {
  return true;
 } 
 if(a!=c)
 {
  return false;
 }

}