#include<iostream>
using namespace std;
float returnCharges(char code, char time, int minutes );
main()
{
char code;
char time;
int minutes;
float charges;
cout <<"Enter which type of customer you are (residential or premium) select(r/p) :";
cin  >> code;
cout << "Enter the time you availed service (d for day and n for night): ";
cin  >> time;
cout << "Enter the number of mins you used the service : ";
cin  >> minutes;
charges = returnCharges(code,time,minutes);
cout << "The charges are : ";
cout << charges << "$";

}
float returnCharges(char code, char time, int minutes )
{   float output;
    if(code == 'r')
    { 
    if(minutes<50)
    {
    output = 10;
    }
    else if(minutes > 50)
    {
    output = ((minutes-50)*0.20) + 10; 
    }
    }
    else if(code =='p')
    {
     if(time=='d')
     {
        if(minutes<75)
        {
            output = 25.00;
        }
        if(minutes>75)
        {
            output = ((minutes - 75)*0.01)+25.00;
        }
     }
     if (time == 'n')
     {
      if (minutes<100)
      {
        output = 25;
      }
      if (minutes>100)
      {
        output = ((minutes-100)*0.05)+25;
      }

     }

    }
    return output;
}