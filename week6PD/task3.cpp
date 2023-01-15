#include<iostream>
using namespace std;
string Zodiac(int date, string month);
main()
{
int date;
string month , output ;
cout << "Enter your birth day ";
cin  >> date;
cout << " Enter your birth month ";
cin  >> month;
output = Zodiac(date, month);
cout << output;

}
string Zodiac(int date, string month)
{
    string zodiac;
if(month == "March" && (date>=21 && date <=30))
{
zodiac = "Aries";
}
if(month == "April" && (date>=1 && date<=19))
{
zodiac = "Aries";
}
if(month == "April" && (date>=20 && date <=30))
{
    zodiac = "Taurus";
}
if(month == "May" && (date>=1 && date <=20))
{
    zodiac = "Taurus";
}
if(month == "May" && (date>=21 && date<=31))
{
zodiac ="Gemini";
}
if(month == "June" && (date>=1 && date<=20))
{
zodiac ="Gemini";
}
if(month == "June" && (date>=21 && date<=30))
{
    zodiac = "Cancer";
}
if(month == "July" && (date>=1 && date<=22))
{
    zodiac = "Cancer";
}
if(month == "July" && (date>=23 && date <=31))
{
    zodiac = "Leo";
}
if(month == "August" && (date>=1 && date <=22))
{
    zodiac = "Leo";
}
if(month == "August" && (date>=23 && date <= 31))
{
    zodiac = "Virgo";
}
if(month == "September" && (date>=1 && date <= 22))
{
    zodiac = "Virgo";
}
if(month == "September" && (date>=23 && date <=30))
{
    zodiac = "Libra";
}
if(month == "October" && (date>=1 && date <= 22))
{
    zodiac = "Libra";
}
if(month == "October" && (date>=23 && date <= 31))
{
    zodiac = "Scorpio";
}
if(month == "November" && (date>=1 && date <= 21))
{
    zodiac = "Scorpio";
}
if(month == "November" && (date >=22 && date <=30))
{
    zodiac = "sagittarius";
}
if(month == "December" && (date >=1 && date <=21))
{
    zodiac = "sagittarius";
}
if(month == "December" && (date >=22 && date <=31))
{
    zodiac = "Capricon";
}
if(month == "January" && (date >=1 && date <=19))
{
    zodiac = "Capricon";
}
if(month == "January" && (date >=20 && date <=31))
{
    zodiac = "Aquarius";
}
if(month == "February" && (date >=1 && date <=18))
{
    zodiac = "Aquarius";
}
if(month == "February" && (date >=19 && date <=29))
{
    zodiac = "Pisces";
}
if(month == "March" && (date >=1 && date <=20))
{
    zodiac = "Pisces";
}
return zodiac;
}