#include<iostream>
using namespace std;

main()
{
   int rollNo;
   string name;
   cout << " Enter roll no.: ";
   cin  >> rollNo ;
   cout << " Enter name: ";
   cin  >> name;
   if( name == "Ali" )
   {
     if(rollNo == 501)
     {
     cout << " Welcome Ali! " << endl;
     }
   }
   else
   {
     cout << " Try again! " << endl;

   }
  
}