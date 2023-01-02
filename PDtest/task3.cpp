#include<iostream>
using namespace std;
main()
{ 
cout << "      Program to find final velocity " ;
cout << endl;
float initialvelocity;
float finalvelocity;
float acceleration;
float time;
cout << " Enter the initial velocity of car :    " ;
cin  >> initialvelocity;
cout << " Enter acceleration of the car     :    " ;
cin  >> acceleration;
cout << " Enter the time                    :    ";
cin  >> time;
finalvelocity = (acceleration*time) + initialvelocity; 
cout << " Final velocity of the car is ";
cout << finalvelocity;
}