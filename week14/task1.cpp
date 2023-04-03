#include<iostream>
using namespace std;
main()
{
int num= 1;
int *p = &num;
cout << "THe address of the num is " << p << endl;
cout << "THe value of the num is " << *p;

}