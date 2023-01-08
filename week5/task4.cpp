#include<iostream>
#include<cmath>
using namespace std;
string isEvenish(int number);
main()
{
  int number;
  string result;
  cout << " Enter any 5-digit number : " ;
  cin  >> number;
  result = isEvenish(number);
  cout << " THE NUMBER IS " << result << endl;
}
string isEvenish(int number)
{
  int a, b, c, d, e;
  int sum;
  a = number % 10;
  b = (number/10) %10;                                                                                                                                                                         
  c = (number/100)%10;
  d = (number/1000)%10;
  e = (number/10000);
  sum = a + b + c + d + e;
   if (sum%2 == 0)
  {
   return "Evenish";
  }
   if (sum%2 != 0)
  {
    return "Oddish";
  }
}

