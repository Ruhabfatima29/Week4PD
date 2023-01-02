#include<iostream>
using namespace std;
main ()
{
string movie;
int adult_tp;
int child_tp;
int a;
int b;
int total;
int donation;
int percentage;
float final ;
cout << " Enter Movie Name : ";
cin >> movie;
cout << " Enter Adult Ticket price : " ;
cin >> adult_tp;
cout << " Enter Child Ticket price ; " ;
cin >> child_tp;
cout << " Enter no. of Adult tickets sold : ";
cin  >> a;
cout << " Enter no. of Child tickets sold : ";
cin  >> b; 
cout << " Enter percentage to donate : ";
cin  >> percentage;
total = (adult_tp * a) + (child_tp * b );
cout << " Total amount generated: ";
cout << total ;
cout << endl;
final = total - (total*0.1);
cout << " Amount after donation : ";
cout << final;
}

 

 