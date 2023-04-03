#include<iostream>
using namespace std;
string words;
main()
{
   
int count = 1;
cout << "Enter the statement: ";
getline(cin,words);
for(int idx=0; words[idx] != '\0'; idx++)
{
    if(words[idx] == ' ')
    {
        count ++;
    }

}
 string letters[count];
for(int idx=0; words[idx] != '\0'; idx++)
{
    letters[idx] = letters[idx] + words[idx]
}




}