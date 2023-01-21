#include<iostream>
using namespace std;
void triangle(int number);
main()
{
int number;
cout << "Enter the triangle number of sequence : ";
cin  >> number;
triangle(number);
}
void triangle(int number)
{
    int sum=0;
for(int count=number; count>=0; count--)
{
    sum = sum+count;
}

cout << sum;

}