#include<iostream>
using namespace std;
void isEligible(int age);
main()
{ 
  int age;
  while(true)
  {
  cout << " Enter your age: ";
  cin  >> age;
  isEligible( age );
  }

}
void isEligible(int age)
 { 
    if(age>=18)
    {
    cout << " AGE IS GREATER THAN OR EQUAL TO 18 " << endl ;
    cout << " YOU ARE ELIGIBLE TO VOTE " << endl ;
    }
    if(age<18)
    { 
     cout << " YOU ARE UNDER EIGTHEEN " << endl ;
     cout << " YOU ARE NOT ELIGIBLE TO VOTE" << endl ;
    }
  }