#include<iostream>
using namespace std;
main()
{
string word;
cout << "Enter word : ";
getline(cin,word);
int count= word.length();
if(count%2==0)
{
    cout << "EVEN";
}
else
{
    cout << "ODD";
}


}