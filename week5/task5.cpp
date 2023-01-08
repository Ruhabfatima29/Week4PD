#include <iostream>
#include<cmath>
using namespace std;
main ()
{
  int  minutes , finalMinutes ,  finalHours;
  cout << " Enter time in hours of a 24 hour_day: ";
  cin  >> finalHours;
  cout << " Enter time in minutes of a 24 hour_day: ";
  cin  >> minutes;
  cout << " You entered " << finalHours <<" hours : " << minutes << " minutes " << endl ;
  finalMinutes = minutes +15;
   if (finalMinutes > 59)
   {
   finalMinutes = finalMinutes - 60;
   finalHours = finalHours + 1;
   }
   if (finalHours > 23)
   {   
   finalHours = finalHours - 24; 
   if (finalHours == 24);
   {
   finalHours = 0;
   }
   }
   cout << " Time after 15 mins is  "  << finalHours << " : " << finalMinutes;
}

