#include <iostream>
using namespace std;
main()
{
    int count = 0;
    string word1, word2;
    cout << "Enter first string: ";
    getline(cin, word1);
    cout << "Enter second string: ";
    getline(cin, word2);
    for (int i = 0; word1[i] != '\0'; i++)
    {
        for (int j = 0; word2[j]!='\0'; j++)
        {
            if (word1[i] == word2[j])
            {

                count++;
                word2[j]= ' ';
                break;
            }
        }
    }
    cout << "THe same characters in the string is " << count;
}