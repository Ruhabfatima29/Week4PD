#include<iostream>
#include<cmath>
using namespace std;
 
main()
{
  float number1;
  float number2;
  float total;
  cout << " Enter number1:";
  cin  >> number1;
  cout << " Enter number2:";
  cin  >> number2;
  total = max(number1 , number2);
  cout <<   total << " is greater number!" << endl;

  total = min(number1 , number2);
  cout <<   total << " is smaller number!" << endl;
  
  total = sqrt (169);
  cout << " The square root of 169 is " << total << endl;

  total = pow (2,4);
  cout << " 2^4 is " << total;
  
  total = cbrt(27);
  cout << " The cube root of 27 is " << total << endl;

  total = ceil(3.9);
  cout << " Ceiling is " << total << endl;

  total = floor(3.9);
  cout << " floor value is " << total << endl;
}