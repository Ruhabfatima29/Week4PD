#include<iostream>
using namespace std;
void isEven(int number);
main()
{
 while(true)
 { 
 int number;
 cout << " Enter any number: ";
 cin >> number;
 isEven(number);
 }
}
void isEven(int number)
{ 
  if(number%2 == 0)
  {
    cout << " The number you entered is EVEN " << endl ;
  }
  if(number%2 != 0)
  {
    cout << " The number you entered is ODD " << endl ;
  }
}