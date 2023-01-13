#include<iostream>
using namespace std;
float totalIncome(string, int, int );
main()
{
string screen;
int rows,columns;
float result;
cout << " Enter screening type: ";
cin  >> screen;
cout << " Enter number of rows: ";
cin >> rows;
cout << " Enter number of columns: ";
cin >> columns;
result = totalIncome(screen, rows, columns);
cout << "The total income from tickets of full hall is " << result;
}
float totalIncome(string screen, int rows, int columns)
{
    float area, output;
    area = rows*columns;
if(screen=="premiere")
{
output = area*12.00;
}
else if(screen=="normal")
{
output = area*7.50;
}
else if(screen=="discount")
{
output = area*5.00;
}

return output;

}