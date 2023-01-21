#include<iostream>
using namespace std;
void returnPercent(int number);
main()
{
int range;
cout << "Enter number : ";
cin >> range;
returnPercent(range);

}
void returnPercent(int number)
{ 
    int value;
    float p1 =0 , p2 =0 , p3 =0;
    float perP1, perP2, perP3;
for(int count=1; count<=number; count++)
{
cout << "Enter number: ";
cin >> value;
if(value%2==0)
{
    p1= p1+1;
}
if(value%3==0)
{
    p2= p2+1;
}
if(value%4==0)
{
    p3= p3+1;
}
}
perP1 = (p1/number)*100;
perP2= (p2/number)*100;
perP3= (p3/number)*100;
cout << perP1 <<"%" <<endl;
cout << perP2 <<"%" <<endl;
cout << perP3 <<"%" <<endl;

}
