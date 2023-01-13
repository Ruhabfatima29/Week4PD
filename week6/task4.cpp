#include<iostream>
using namespace std ;
string checkSpeed(float speed);
main()
{
 float speed;
 string result;
 cout << "Enter speed:";
 cin  >> speed;
result = checkSpeed(speed);
cout << "Your speed is " << result;


}
string checkSpeed( float speed)
{ 
string output;
if(speed <=10)
{
output = "slow";
}
else if( speed > 10 && speed <= 50)
{
output = "average";
}
else if(speed > 50 && speed<=150)
{
    output = "fast";
}
else if (speed>150 && speed <=1000)
{
output = "ultra-fast";
} 
else if (speed>1000)
{
    output = "extreme-fast"; 
}
else
{
    output = "!!!";
}
return output;
}