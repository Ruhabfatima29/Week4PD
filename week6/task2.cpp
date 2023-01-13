#include <iostream>
using namespace std;
float discount(string day, string month, int amount);
main()
{
  float amount;
  string day, month;
  float result;
  cout << " Enter DAY : ";
  cin >> day;
  cout << " Enter Month: ";
  cin >> month;
  cout << " Enter Amount: ";
  cin >> amount;
  result = discount(day, month, amount);
  cout << " Your discounted price is " << result;
}
float discount(string day, string month, int amount)
{
  float final = amount ;
  if (day == "sunday")
  {
    if ((month == "october" || month == "march") || month == "august")
    {
      final = amount - amount * 0.1;
    }
  }
  if (day == "monday")
  {
    if (month == "november" || month == "december")
    {
      final = amount - amount * 0.05;
    }
  }
  return final;
}