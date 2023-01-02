#include<iostream>
#include<windows.h>
using namespace std;
void numFlowers( float redroses, float white, float tulips);
main()
{
  float  redRoses, whiteRoses, tulips;
  cout << " Enter no. of Red roses : ";
  cin  >> redRoses;
  cout << " Enter no. of White roses : ";
  cin  >> whiteRoses;
  cout << " Enter no. of Tulips : ";
  cin  >> tulips;
 numFlowers(  redRoses, whiteRoses, tulips); 

}
void numFlowers( float redroses, float white, float tulips)
{
  float total;
  total = redroses*2.00 + white*4.10 + tulips*2.50;
  cout << " The original price is " << total << endl;
  float discount = total*0.2;
  if (total > 200)
  {
   float final = total-discount;
   cout << " The discounted price is " << final;
  }
}
