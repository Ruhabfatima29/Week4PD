#include<iostream>
#include<windows.h>
using namespace std;
void isEqual(int x, int y);
main()
{
  int num1, num2;
  cout << " Enter any no. ";
  cin >> num1;
  cout << " Enter any no. ";
  cin >> num2;
  isEqual(num1, num2);
}
void isEqual( int x, int y)
{
  if( x==y)
  {
  cout << " TRUE ";
  }
  if(x!=y)
  { 
  cout << " FALSE " ;
  }
}
  
