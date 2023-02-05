#include<iostream>
using namespace std;
main()
{
string name;
int count = 0;
cout << "Enter name: ";
getline(cin, name);
for (int idx=0; name[idx]!=0; idx++)
{
if(name[idx]=='a'||name[idx]=='e' || name[idx]=='i'|| name[idx]=='o'|| name[idx]=='u' )
{
    count++;
}
}
 cout << count;

}