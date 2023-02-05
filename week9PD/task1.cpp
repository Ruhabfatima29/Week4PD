#include<iostream>
using namespace std;
main()
{
int prices[4]={60,70,40,30};
float price;
string fruits[4]={"peach", "apple", "guava", "watermelon"};
string name;
int quantity;
cout << "Enter fruit name: ";
cin  >> name;
cout << "Enter quantity in kg: ";
cin >> quantity;
for(int index=0; index<4; index++)
{
    if(name  == fruits[index])
    {
    price = prices[index] * quantity;
    }
}
cout << "The price for " << quantity << " kg " << name << " is " << price;
}