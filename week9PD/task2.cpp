#include<iostream>
using namespace std;
main()
{
    float price;
string movies[5]={"Gladiator", "StarWars","Terminator", "TakingLives", "TombRider"};
string name;
cout << "Enter movie name:  ";
cin >> name; 
for(int idx =0; idx<5; idx++)
{
if (name == movies[idx])
{
    if(idx%2 == 0 )
    {
        price = 500 - (500*0.1);
    }
    else
    {
        price = 500 - (500*0.5);
    }
}
}
cout << "The discounted price is " << price;
}