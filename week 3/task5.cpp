#include<iostream>
using namespace std;
main()
{
float current;
int time;
float charge;
cout << "ENTER CHARGE :";
cin  >> charge;
cout << "ENTER TIME   :";
cin  >> time;
current = charge/time;
cout <<"Current is " ;
cout << current;
}