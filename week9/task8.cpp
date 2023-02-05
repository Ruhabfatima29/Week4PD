#include<iostream>
using namespace std;
main()
{
string word;
cout << "Enter word you want to reverse: ";
getline(cin,word);
int count= word.length();

for(int idx=count; idx>=0; idx--)
{
    cout << word[idx];
}
}