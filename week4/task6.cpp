#include<iostream>
using namespace std;
void calculateBill(string day, int amount);
main()
{
  int amount;
  string day;
  while(true)
  {
  cout << " Enter the Day: " ;
  cin  >> day;
  cout << " Enter Total Amount: ";
  cin  >> amount;
  calculateBill(day,amount);
  }
}
void calculateBill(string day, int amount)
{
   if(day == "sunday")
   { 
    int discount = amount*0.1;
    int total   = amount - discount;
    cout << " Your Payable Amount is " << total << endl ;
    }
   if(day == "monday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
      if(day == "tueday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
     if(day == "wednesday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
      if(day == "thursday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
      if(day == "friday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
         if(day == "saturday")
    {
     int discount = amount * 0.05;
     int total    = amount - discount;
     cout << " Your Payable Amount is " << total << endl;
    } 
}