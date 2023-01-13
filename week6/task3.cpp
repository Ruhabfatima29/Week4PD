#include <iostream>
using namespace std;
string title(float ,char);
main()
{
float age ;
char gender ;
string result;
cout << " Enter your age : ";
cin  >> age;
cout << " Enter your gender [f for female, m for male] : ";
cin  >> gender;
result = title (age , gender);
cout << " Your title is : " << result;

}
string title(float age ,char gender)
{
    string result;
if(gender=='m')
{
if(age>=16)
{ 
   result = "Mr." ;
}
if (age<16)
{
    result = "Master"; 
}
}
if (gender == 'f')
{
    if (age>=16)
    {
        result = "Ms.";
    }
    if(age<16)
    {
        result = "Miss";
    }
}
return result;
}


