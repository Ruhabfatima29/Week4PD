#include<iostream>
using namespace std;
main()
{
string word;
char letter;
string check= "Absent";
cout << "Enter the word: ";
cin  >> word;
cout << "Enter the letter you want to find: ";
cin >>letter;
for(int idx=0; word[idx]!='\0'; idx++)
{
    if(word[idx]==letter)
    {
     check = "Present";
    }
}
  cout <<  check;
}
