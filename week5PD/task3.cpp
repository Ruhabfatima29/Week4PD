#include<iostream>
using namespace std;
float taxCalculator (char code, float price);
main()
{
  int price;
  char code;
  float taxRate;
  string vehicleType;
  cout << " Enter the Price: ";
  cin >> price;
  cout << " Enter the code of item [ M, E, S, V, T] :";
  cin >> code;
  taxRate = taxCalculator( code, price);
  if( code == 'M')
  {
  vehicleType = " Motorcycle "; 
  }
  if( code == 'E')
  {
  vehicleType = " Electric "; 
  }
  if( code == 'S')
  {
  vehicleType = " Sedan"; 
  }
  if( code == 'V')
  {
  vehicleType = " Van "; 
  }
  if( code == 'T')
  {
  vehicleType = "Truck";
  }
  cout << " The final price on a vehicle of type " << vehicleType  << " after adding tax is " << taxRate ;
}
float taxCalculator (char code, float price)
{
  float taxrate;
  float finalPrice;
  float taxAmount;
  if( code == 'M')
  {
  taxrate = 0.06;
  }
  if( code == 'E')
  {
  taxrate = 0.08;
  }
  if( code == 'S')
  {
  taxrate = 0.1;
  }
  if( code == 'V')
  {
  taxrate = 0.12;
  }
  if( code == 'T')
  {
  taxrate = 0.15;
  }
  taxAmount = price*taxrate;
  finalPrice = price + taxAmount;
  return finalPrice ;
}
