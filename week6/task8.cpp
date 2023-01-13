#include <iostream>
using namespace std;
float ticketPrice(int quantity, string ticket);
float returnTotal(float budget, string ticket, int quantity);
main()
{
    string ticket;
    float budget, result, money;
    int quantity;
    cout << "Enter your budget : ";
    cin >> budget;
    cout << "Enter your ticket category: ";
    cin >> ticket;
    cout << "Enter the no. of passengers: ";
    cin >> quantity;
    result = returnTotal(budget, ticket, quantity);
    if(result >budget)
    {
    money = result - budget;
    cout << "Not enough money! You need " << money << "QR";
    }
    if(result < budget)
    {
    money = budget - result;
    cout << "Yes! you have " << money << " QR left";
    }
}
float returnTotal(float budget, string ticket, int quantity)
{
    float transportation , result ;
    float ticketCost = ticketPrice(quantity , ticket);
    if(quantity >= 1 && quantity <= 4)
    {
    transportation = budget * 0.75; 
    }
    if(quantity >= 5 && quantity <= 9)
    {
    transportation = budget * 0.6; 
    }
    if(quantity >= 10 && quantity <= 24)
    {
    transportation = budget * 0.5; 
    }
    if(quantity >= 25 && quantity <= 49)
    {
    transportation = budget * 0.4; 
    }
    if(quantity >= 50)
    {
    transportation = budget * 0.25; 
    }
    result = ticketCost + transportation;
    return result;
}
float ticketPrice(int quantity, string ticket)
{
   float Price;
    if (ticket == "vip")
    {
        Price = quantity * 499.99;
    }
    if(ticket == "normal")
    {
        Price= quantity* 249.99;
    }
    return Price;
}