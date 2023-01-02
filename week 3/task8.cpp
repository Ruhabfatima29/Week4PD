#include<iostream>
using namespace std;
main()
{
double KB;
double Bytes;
double MB;
double Bit;
cout <<" Enter Bits : ";
cin  >> Bit;
Bytes= 8*Bit;
cout << Bit << " Bits is equal to " << Bytes << " Bytes";
cout <<endl;
KB = Bit*8000 ;
cout << Bit  << " Bits is equal to " << KB   << " KB";
cout << endl;
MB = Bit * 8000000;
cout << Bit  << " Bits is equal to " << MB   << " MB";





}