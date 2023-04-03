#include <iostream>
using namespace std;
int checkCondition(string word, char letter);
main()
{
    int size;
    int sum = 0;
    char letter;
    cout << "Enter how many words you want to enter: ";
    cin >> size;
    string words[size];
    // for taking inputs
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter word " << idx + 1 << ":";
        cin >> words[idx];
    }
    cout << "Enter the letter you want to count: ";
    cin >> letter;
    // for calculating number of times
    for (int idx = 0; idx < size; idx++)
    {
        string word = words[idx];
        sum = sum + checkCondition(word, letter);
        
    }
    cout << "The letter " << letter << " is " << sum << " times in the strings. " << endl;
}
int checkCondition(string word, char letter)
{
    int count = 0;
    for (int index = 0; word[index] != '\0'; index++)
    {
        if (word[index] == letter)
        {
            count++;
        }
        }
    return count;
}