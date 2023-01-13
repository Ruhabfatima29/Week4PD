#include<iostream>
#include<cmath>
using namespace std;
float playing(string year, int holidays, int weekends);
main()
{
string year;
int holidays;
int weekends;
int result;
cout << "Enter the year : ";
cin  >> year;
cout << " Enter no.of holidays[p] : ";
cin  >> holidays;
cout << " Enter no. of weekends[h] : ";
cin  >> weekends;
result = playing( year, holidays, weekends);
cout << result;
}
float playing(string year, int holidays, int weekends)
{
float holidayNo  , total, totalWeekends; 
int freeWeekends;
holidayNo = (2/3) * holidays;
freeWeekends = 48 - weekends;
totalWeekends = (freeWeekends*3/4) + holidays;
if( year == "normal")
{
total = holidayNo + totalWeekends;
total = ceil(total);
}
if( year == "leap")
{
total = holidayNo + totalWeekends;    
total = total + (total*0.15);
total = ceil(total);
}
return total;
}