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
for(int row= rowNo; row>=1; row--)
{
    for(int column=row; column>=1; column--)
    {
        cout << "*";
    }
    cout << endl;
}

}