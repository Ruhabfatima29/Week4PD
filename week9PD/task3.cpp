#include<iostream>
using namespace std;
main()
{
    int size;
string word;
cout << "Enter staement: ";
getline(cin,word);
size = word.length();
if(size%2 ==0)
{
    cout << "True";
}
else
{
    cout << "False";
}

}