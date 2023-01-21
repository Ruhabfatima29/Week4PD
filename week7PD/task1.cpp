#include<iostream>
using namespace std;
void printShape(int);
main()
{
int rowNo;
cout << "Enter number of rows: " ; 
cin >> rowNo;
printShape(rowNo);


}
void printShape(int rowNo)
{
for(int row= 1; row<=rowNo; row++)
{
    for(int column=1; column<=row; column++)
    {
        cout << "*";
    }
    cout << endl;
}

}