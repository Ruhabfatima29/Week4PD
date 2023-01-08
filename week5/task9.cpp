#include<iostream>
#include<cmath>
using namespace std;
float disc( float a, float b, float c);
float positiveValueX ( float b , float disc, float a);
float negativeValueX ( float b , float disc, float a);
main()
{
  float a  ;
  float b  ; 
  float c ;
  float discriminant , final;
  cout << " Enter the coefficient of x^2 :";
  cin  >> a;
  cout << " Enter the coefficient of x :";
  cin  >> b;
  cout << " Enter the constant term of quadratic eq. : ";
  cin  >> c;
  discriminant =  disc( a, b, c);
  final = positiveValueX (  b , discriminant , a);
  cout << " The value of x is : " << final << endl;
  final = negativeValueX (  b , discriminant , a);
  cout << " The value of x is : " << final << endl;
}
float positiveValueX ( float b , float disc, float a)
{
  float x;
  x = (-b + disc)/(2*a);
  return x;
}
float negativeValueX ( float b , float disc, float a)
{
  float x;
  x = (-b - disc)/(2*a);
  return x;
}

float disc( float a, float b, float c)
{
  float  y , product;
  float disc;
  float square;
  square = pow(b,2);
  product = 4*a*c;
  y = square - product;
  disc = sqrt(y);
  return disc; 
}