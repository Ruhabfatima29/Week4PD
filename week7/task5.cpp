#include <iostream>
using namespace std;
int digitSum(int number);
main()
{
    int number , result ;
    cout << "Enter any number : ";
    cin >> number;
    result = digitSum(number);
    cout << result;
}
int digitSum(int number)
{
    int result, sum = 0;
    while (number > 0)
    {
        result = number % 10;
        sum = sum + result;
        number = number / 10;
    }
    return sum;
}