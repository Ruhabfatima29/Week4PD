#include<iostream>
#include<cmath>
using namespace std;
float height(float angle, float base);
main()
{
  float angle;
  float base;
  float final;
  cout << " Enter the base : ";
  cin >> base;
  cout << " Enter the angle of elevation: " ;
  cin  >> angle;
  final = height( base, angle);
  cout << " The height of the tree is " << final << endl ;
  
}
float height(float base, float angle)
{
  float height;
  float radians;
  radians = angle / 57.2958;
  height = tan(radians) * base;
  return height;


}