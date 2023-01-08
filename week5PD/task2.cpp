#include <iostream>
using namespace std;
int calculateVolume( int length, int width, int height);
double pyramidVolume( int volume , string unit);
main()
{
 int length;
 int width;
 int height;
 int volume;
 string unit;
 double final;
 cout << " Enter length in meters: " ;
 cin  >> length;
 cout << " Enter width in meters: ";
 cin  >> width;
 cout << " Enter height in meters : "; 
 cin  >> height;
 cout << " Enter the unit in which you want output : " ;
 cin  >> unit;
 volume = calculateVolume( length,  width, height);
 final = pyramidVolume( volume , unit);
 cout << " The volume of pyramid in " << unit << " is " << final;


}
int calculateVolume( int length, int width, int height)
{
 int result;
 result = ( length * width * height ) / 3;
 return result;

}
double pyramidVolume( int volume , string unit)
{ 
  double output;
  if( unit == "centimeters") 
  {
   output = volume * 1000000;
   return output;
  }
  if ( unit == "millimeters" )
  {
   output = volume*(1000*1000*1000);
   return output;  
  }
  if ( unit == " kilometers")
  {
   output = volume / (1000*1000*1000);
   return output;

  }

}