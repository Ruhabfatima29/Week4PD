#include<iostream>
#include<conio.h>
using namespace std;
int cars[5][5] = { {10, 7, 12,10,4}, 
                   {18,11,15,17,2},
                   {23, 19, 12, 16,14}, {7,12,16,0,2},
                   {3,5,6,2,1}
                 };
main()
{
    int sum = 0;
 for(int col=0; col<5; col++)
 {
    for(int row=0; row< 5; row++)
 {
    sum = sum + cars[col][row];
 }
//  cout << endl;
 }
 cout << "Sum is " << sum;
}