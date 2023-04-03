#include <iostream>
using namespace std;

main()
{
    int size;
    char letter;
    cout << "Enter how many words you want to enter: ";
    cin >> size;
    int count = 0;
    string words[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter word " << idx + 1 << ":";
        cin >> words[idx];
    }
    cout << "Enter the letter you want to count: ";
    cin >> letter;
    for (int idx = 0; idx < size; idx++)
    {
        string word = words[idx];
        for (int index = 0; word[index] != '\0'; index++)
        {
            if (word[index] == letter)
            {
                count++;
            }
        }
    }
    cout << "The letter" << letter << " is " << count << " times in the strings. " << endl;
}