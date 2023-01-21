#include<iostream>
using namespace std;
void printTable(int);
main()
{
    int number;
    cout << "Enter any number: ";
    cin  >> number;
    printTable(number);
}
void printTable(int number)
{
    for(int count = 1; count<= 10; count++)
    {
    int product;
    product = number*count;
    cout << number << "*" << count << "= " << product << endl;

    }
}