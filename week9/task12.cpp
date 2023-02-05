#include<iostream>
using namespace std;
main()
{
string word,letter;
cout << "Enter word:";
getline(cin,word);
for(int idx=0; word[idx]!=0; idx++)
{
letter = word[idx]+1;
cout << letter;
}


}