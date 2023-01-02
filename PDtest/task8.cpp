#include<iostream>
using namespace std;
main ()
{
float vege_price ;
float fruit_price;
int  vege_kg;
int  fruit_kg;
float fruit_cost;
float vege_cost; 
float total ;
cout << " Enter vegetable price per kg : ";
cin >> vege_price;
cout << " Enter fruits price per kg : ";
cin >> fruit_price;
cout << " Total kilograms of vegetables : ";
cin >> vege_kg;
cout << " Total kilograms of fruits: ";
cin >> fruit_kg;
cout << " The vegetable cost is ";
vege_cost = (vege_price * vege_kg) ;
cout << vege_cost;
cout << endl;
fruit_cost = fruit_price*fruit_kg;
cout << " The fruits cost is  " ;
cout << fruit_cost; 
cout << endl;
total= (fruit_cost + vege_cost) / 1.94;
cout <<" THe total price is " << total;

}
