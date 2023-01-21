#include <iostream>
using namespace std;
float calculateMoney(int age, float price, int toy_price);
main()
{
    int age;
    float price, result;
    int toy_price;
    cout << "Enter Lilly's Age: ";
    cin >> age;
    cout << "Enter IPHONE price: ";
    cin >> price;
    cout << "Enter the unit price of toys: ";
    cin >> toy_price;
    result = calculateMoney(age, price, toy_price);
    if (result >= price)
    {
        cout << "YES!!" << endl;
        cout << result - price;
    }
    else
    {
        cout << "NO!" << endl;
        cout << price - result;
    }
}
float calculateMoney(int age, float price, int toy_price)
{
    int moneyGift, toyGift, total;
    int odd = 0, even = 0, sum = 0 ,n1=0;
    for (int count = 1; count <= age; count++)
    {
        if (count % 2 == 0)
        {
            n1= n1+1;
            even = even + 10;
            sum = sum + even;
        }
        else
        {
            odd = odd + 1;
        }
    }
    moneyGift = sum - n1;
    toyGift = odd * toy_price;
    total = moneyGift + toyGift;
    return total;
}
