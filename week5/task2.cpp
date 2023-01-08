#include<iostream>
using namespace std;
string returnOutput(char name);
main()
{
  char name;
  string result;
  cout << " Enter 'A' or 'a' : ";
  cin >> name;
  result = returnOutput(name);
  cout  << " User entered : " << result << endl; 
}
string returnOutput(char name)
{
  if(name == 'a')
  {
   return "SmallCase";
  }
  if(name == 'A')
  {
   return "CapitalCase";
  }

}