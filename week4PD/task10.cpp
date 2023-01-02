#include<iostream>
#include<windows.h>
using namespace std;
void printDiscount(string name, int price);
main()
{
  string name;
  int price;
  while(true)
  {
  cout << " Enter your country name: ";
  cin >> name;
  cout << " Enter ticket price in dollars ";
  cin >> price;
  printDiscount( name, price );
  }

}
void printDiscount(string name, int price)
{
  int total;
  if( name == "pakistan")
  {
  int discount = price*0.05;
  total = price - discount;
  cout << " The final price of ticket is " << total <<endl;
  }
 if( name == "ireland")
  {
  int discount = price*0.1;
  total = price - discount;
  cout << " The final price of ticket is " << total << endl;
  }
 if( name == "india")
  {
  int discount = price*0.2;
  total = price - discount;
  cout << " The final price of ticket is " << total << endl;
  }
 if( name == "england")
  {
  int discount = price*0.3;
  total = price - discount;
  cout << " The final price of ticket is " << total << endl;
  }
 if( name == "canada")
  {
  int discount = price*0.45;
  total = price - discount;
  cout << " The final price of ticket is " << total << endl;
  }
}
