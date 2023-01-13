#include<iostream>
using namespace std;
float returnCost(string city, string product , int quantity);
main()
{
string city, product;
int quantity;
float result;
cout << "Your city: " ;
cin  >> city;
cout << "Your product:";
cin  >> product;
cout << "Enter the quantity of yoyr products: ";
cin  >> quantity;
result = returnCost( city, product , quantity);
cout << "Your payable price is : " << result;

}
float returnCost(string city, string product , int quantity)
{
float price;
if (city=="sofia")
{ 
 if(product == "coffee")
{ 
price = 0.50*quantity;
}
if(product == "water")
{ 
price = 0.80*quantity;
}
if(product == "beer")
{ 
price = 1.20*quantity;
}
if(product == "sweets")
{ 
price = 1.45*quantity;
}
if(product == "peanuts")
{ 
price = 1.60*quantity;
}
}
else if(city == "plovdiv")
{
 if(product == "coffee")
{ 
price = 0.40*quantity;
}
if(product == "water")
{ 
price = 0.70*quantity;
}
if(product == "beer")
{ 
price = 1.15*quantity;
}
if(product == "sweets")
{ 
price = 1.30*quantity;
}
if(product == "peanuts")
{ 
price = 1.50*quantity;
}
}
if(city == "varna")
{
 if(product == "coffee")
{ 
price = 0.45*quantity;
}
if(product == "water")
{ 
price = 0.70*quantity;
}
if(product == "beer")
{ 
price = 1.10*quantity;
}
if(product == "sweets")
{ 
price = 1.35*quantity;
}
if(product == "peanuts")
{ 
price = 1.55*quantity;
}
}
return price;
}






