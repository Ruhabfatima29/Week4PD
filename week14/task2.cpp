#include<iostream>
using namespace std;
void swappingFunction(int & num1, int &num2 )
{
    int swap= num1;
    num1 = num2;
    num2 = swap; 
}
main()
{
int number1 = 45;
int number2 = 50;
cout << "Before swapping, number1 is " << number1 << " and number2 is " << number2 << endl;
swappingFunction(number1,number2);
cout << "After swapping, number1 is " << number1 << " and number2 is " << number2;

}