#include<iostream>
#include<windows.h>
using namespace std;
void reverse(string);
main()
{
  string name;
  cout << " Enter true or false : ";
  cin >> name;
  reverse(name);
}
void reverse( string value )
{
   if( value == "true" )
   {
   cout << " FALSE ";
   }
   if( value == "false" )
   {
   cout << " TRUE " ;
   }
}