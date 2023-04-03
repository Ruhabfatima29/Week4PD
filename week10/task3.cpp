#include <iostream>
using namespace std;
bool checkCondition(int pre, int current, int next);
main()
{
    int size;
    cout << "Enter how many numbers you want to store: ";
    cin >> size;
    int numbers[size];
    bool flag=false;
    int i = 0;
    int final[i];
    // input data
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> numbers[idx];
    }
    // count numbers
    for (int idx = 1; idx < size-1; idx++)
    {
        flag = checkCondition(numbers[idx-1], numbers[idx], numbers[idx+1]);
        if(flag==true)
        {
            final[i]= numbers[idx];
            i++;
        }

    }
    if(i!=0)
    {
    for (int index=0; index<i; index++)
    {
        cout << final[index] << " ";
    }
    }
    else
    {
        cout << "No such numbers!!!";
    }
}
bool checkCondition(int pre, int current, int next)
{
if(current>pre && current > next)
{
    return true;
}
return false;
}
