#include<iostream>
using namespace std;
string activity (string, string);
main()
{
string temperature;
string humidity;
string result;
cout <<"Enter temperature: " ;
cin  >> temperature;
cout << "Enter humidity: " ;
cin  >> humidity;
result = activity(temperature , humidity);
cout << result;
}
string activity (string temperature, string humidity)
{
    string output ;
if(temperature =="warm" && humidity =="dry")
{
 output= "play tennis";   
}
if(temperature =="warm" && humidity =="humid")
{
 output= "swim";   
}
if(temperature =="cold" && humidity =="dry")
{
 output= "play basketball";   
}
if(temperature =="cold" && humidity =="humid")
{
 output= "watch tv";   
}
return output;



}
