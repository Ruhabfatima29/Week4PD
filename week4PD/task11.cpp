#include<iostream>
#include<windows.h>
using namespace std;
void printChallan(int);
main()
{
  int speed;
  cout << " Enter the speed of car : " ;
  cin >> speed;
  printChallan(speed);
}
void printChallan(int speed)
{
  if(speed>100)
  {
  cout << "Halt... You will be challenged.";
  } 
  if(speed<=100)
  {
  cout << "Perfect! You're doing Great...";
  }
}                   