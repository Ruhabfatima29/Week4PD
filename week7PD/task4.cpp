#include<iostream>
using namespace std;
void function(int number);
main()
{
int number;
cout << "Enter number: ";
cin >> number;
function(number);

}
void function(int number)
{
for (int count =1; count <= number; count ++)
{
if(count%4 == 0 )
{
    cout << count*10 << ",";
}
else
{
cout << count << ",";
}
}

}
