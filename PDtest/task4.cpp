#include<iostream>
using namespace std;
main()
{
string name ;
float marks1, marks2, marks3, marks4, marks5, percentage;
cout << " Enter Your Name: ";
cin  >> name;
cout << " Enter subject 01 marks:  ";
cin  >> marks1;
cout << " Enter subject 02 marks:  ";
cin  >> marks2;
cout << " Enter subject 03 marks:  ";
cin  >> marks3;
cout << " Enter subject 04 marks:  ";
cin  >> marks4;
cout << " Enter subject 05 marks:  ";
cin  >> marks5;
percentage = (marks1 + marks2 + marks3 + marks4 + marks5)/500 * 100 ;
cout << " Your percentage is " ;
cout << percentage;
}