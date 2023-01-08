#include<iostream>
using namespace std;
string function (int number);
string result (int number);
main()
{
  int number, a,b;
  string  tens , ones;
  cout << " Enter any no. [1...99] : ";
  cin >> number;
  a = number%10; 
  b = number / 10;
  tens = result (b);
  cout << tens;
  ones = function(a);
  cout << ones ;
}

string function (int a)
{
  string output;
  if ( a == 1)
  {
   output = " one";
   return output;
  } 
   if ( a == 2)
  {
   output = " two";
   return output;
  } 
   if ( a == 3)
  {
   output = " three";
   return output;
  } 
   if ( a == 4)
  {
   output = "four";
   return output;
  } 
   if ( a == 5)
  {
   output = " five ";
   return output;
  } 
   if ( a == 6)
  {
   output = " six ";
   return output;
  } 
   if ( a == 7)
  {
   output = " seven ";
   return output;
  } 
   if ( a == 8)
  {
   output = " eight ";
   return output;
  } 
     if ( a == 9)
  {
   output = " nine ";
   return output;
  } 
}
string result (int b)
{
 string final;
 if( b ==2 )
 {
   final = " Twenty";
   return final;
 }
 if( b == 3 )
 {
   final = " Thirty";
   return final;
 }
 if( b == 4 )
 {
   final = " Forty";
   return final;
 }
 if( b == 5 )
 {
   final = " Fifty";
   return final;
 }
 if( b == 6 )
 {
   final = " sixty";
   return final;
 }
 if( b == 7 )
 {
   final = " Seventy";
   return final;
 }
 if( b == 8 )
 {
   final = " Eighty";
   return final;
 }
 if( b == 9 )
 {
   final = " Ninety";
   return final;
 }
 


}