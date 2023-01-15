#include<iostream>
using namespace std;
float returnPrice(string fruit, string day, float quantity);
main()
{
string day;
string fruit;
float quantity , output ;
cout << "Enter Day : " ;
cin  >> day;
cout << "Enter Fruit : ";
cin  >> fruit ;
cout << "Enter quantity : ";
cin  >> quantity;
output= returnPrice(fruit, day, quantity); 
cout << "The price is : " << output;
}
float returnPrice(string fruit, string day, float quantity)
{
    float price;
    if (fruit != "banana" && fruit != "apple" && fruit!= "orange" && fruit!= "grapefruit" && fruit != "kiwi" && fruit != "pineapple" && fruit != "grapes")
    {
        cout << " ERROR!!!";
    }
if(day == "monday"|| day == "tuesday" || day =="wednesday" || day == "thursday" || day == "friday" )
{
if(fruit == "banana");
{
price = quantity*2.50;
}
if(fruit == "apple");
{
price = quantity*1.20;
}
if(fruit == "orange");
{
price = quantity*0.85;
}
if(fruit == "grapefruit");
{
price = quantity*1.45;
}
if(fruit == "kiwi");
{
price = quantity*2.70;
}
if(fruit == "pineapple");
{
price = quantity*5.50;
}
if(fruit == "grapes");
{
price = quantity*3.85;
}
}
else if (day == "saturday"|| day == "sunday")
{
if(fruit == "banana");
{
price = quantity*2.70;
}
if(fruit == "apple");
{
price = quantity*1.25;
}
if(fruit == "orange");
{
price = quantity*0.90;
}
if(fruit == "grapefruit");
{
price = quantity*1.60;
}
if(fruit == "kiwi");
{
price = quantity*3.00;
}
if(fruit == "pineapple");
{
price = quantity*5.60;
}
if(fruit == "grapes");
{
price = quantity*4.20;
}
}
return price;
}
