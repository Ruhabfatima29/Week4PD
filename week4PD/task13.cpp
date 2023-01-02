#include<iostream>
#include<windows.h>
void sleep(int);
using namespace std;
main ()
{
  int holidays;  
  cout << " Enter no. of holidays : ";
  cin >> holidays;
  sleep(holidays);
  


}
void sleep(int holidays)
{
   int workingdays = 365 - holidays;
   int time = (workingdays*63)+(holidays*127);
   int difference = 30000 - time;
   int hours = difference / 60;
   int minutes = difference % 60;
   cout << " The difference is " << hours << " hours and " << minutes <<"minutes" << endl;
   if(time <= 30000)
   {
   cout << " Tom sleeps weLL ";
   }
   if(time > 30000)
   {
   cout << " TOm will run away";
   }
}

  