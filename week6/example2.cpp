#include<iostream>
using namespace std;
int isGreater(int, int , int );
 
main()
{
   int number1, number2 ,number3;
   int result;
   cout << " Enter number1: ";
   cin  >> number1;
   cout << " Enter number2: ";
   cin  >> number2;
   cout << " Enter number3: ";
   cin  >> number3;
   result =isGreater( number1,number2,number3);
   cout << " The greatest number is " << result;

}
int isGreater(int number1, int number2, int number3)
{
   int greatest;

   if(number1 >number2 && number1> number3)
   {
     greatest = number1;
   }

   else if ( number2 > number1 && number2 > number3)
   {
    greatest = number2;
   }

   else if ( number3 > number1 && number3 > number2)
   {
   greatest = number3;
   }
   else
   {
   greatest = number1;
   }
   return greatest;


}