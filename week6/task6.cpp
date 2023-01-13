#include<iostream>
using namespace std;
float lowestPrice(int km, string transport);
main()
{
int kilometers;
string time;
float result;
cout << "Enter number of kilometers you want to travel:";
cin  >> kilometers;
cout << "Enter day or night: ";
cin >> time;
result = lowestPrice(kilometers, time);
cout << "The lowest price for given number of kilometers is : " << result;


}
float lowestPrice( int kilometer, string time)
{ 
    float output;
if (kilometer<20)
{
    if (time=="day")
    {
       output = kilometer*0.79+0.70;  
    }
    else if(time=="night")
    {
      output = kilometer*0.90+0.70;
    }
    return output;
}
if (kilometer>20 && kilometer<100)
{
output=kilometer*0.09;
}
if(kilometer>=100)
{
output = kilometer*0.06;
}

return output;
}




