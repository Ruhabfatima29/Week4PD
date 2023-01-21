#include <iostream>
using namespace std;
float calculatePrice(float money, int year);
main()
{
    float money, result;
    int year;
    cout << "Enter the money Ivan recieved as inheritance : ";
    cin >> money;
    cout << "Enter the year he wants to travel to : ";
    cin >> year;
    result = calculatePrice(money, year);
    if (money > result)
    {
        cout << "Yes! He will have a carefree life and will have " << money - result << " dollars left.";
    }
    else
    {
        cout << "He will need " << result - money << " dollars to survive";
    }
}
float calculatePrice(float money, int year)
{
    float evenYear = 0, oddYear = 0, total, odd;
    int age = 18;
    for (int count = 1800; count <= year; count++)
    {
        if (count > 1800)
        {
            age = age + 1;
        }
        if (count % 2 == 0)
        {
            evenYear = evenYear + 12000;
        }
        else
        {
            odd = (12000 + 50 * (age));
            oddYear = odd + oddYear;
        }
    }
    total = evenYear + oddYear;
    return total;
}