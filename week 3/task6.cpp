#include<iostream>
using namespace std;
main()
{
float matric;
float intermediate;
float ecat;
float A;
float B;
float C;
float aggregate;
cout <<" ENTER MATRIC MARKS      : ";
cin  >>matric;
cout <<" ENTER INTERMEDIATE MARKS:";
cin  >>intermediate;
cout <<" ENTER ECAT MARKS        :";
cin  >> ecat;
A = (ecat/400) *50;
B = (intermediate/1100) *40;
C = (matric/1100) *10 ;
aggregate =A+B+C;
cout <<"AGGREGATE IS   ";
cout <<aggregate;
}
