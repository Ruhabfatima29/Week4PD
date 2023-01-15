#include<iostream>
using namespace std;
float apartmentPrice( string month, int days);
float studioPrice( string month , int days);
main()
{
string month;
int days;
float result, output;
cout << "Enter month : ";
cin  >> month;
cout << "Enter days : ";
cin  >> days;
result = apartmentPrice(month, days);
cout << " Apartment: " << result << "$" << endl;
output = studioPrice(  month , days);
cout << "Studio : " << output << "$";
}
float apartmentPrice( string month, int days)
{
float price , discount , discountedPrice;
if (month == "May" || month =="October")
{
price = days*65;
}
if(month == "June" || month == "September")
{
price = days*68.70;
}
if (month == "July" || month == "August")
{
price = days* 77;
}
discount = price*0.10;
discountedPrice = price - discount;
return discountedPrice;
}
float studioPrice( string month , int days)
{
float price , discount , discountedPrice;
if (month == "May" || month =="October")
{
discountedPrice = days*50;
}
else if(month == "June" || month == "September")
{
discountedPrice = days*75.20;
}
else if (month == "July" || month == "August")
{
discountedPrice = days*76;
}
if((month == "May" || month =="October") && days > 7)
{
    discount = price*0.05;
    discountedPrice = price - discount;
}
else if ((month == "May" || month =="October") && days > 14)
{
    discount = price*0.3;
    discountedPrice = price - discount;
}
else if ((month == "June" || month == "September") && days > 14)
{
    discount = price*0.2;
    discountedPrice = price - discount;
}
return discountedPrice;
}