#include <iostream>
using namespace std;
main()
{
    int count=0, time;
    int arr_size;
    cout << "Enter array size: ";
    cin >> arr_size;
    string colors[arr_size];
for(int index=0; index< arr_size; index++)
{
cout << "Enter Colors: ";
cin >> colors[index];

}
for(int index=0; index< arr_size; index++)
{
if(colors[0]==colors[index])
{
    count = count+1;
}
}
time = (arr_size*2)+(arr_size-count);
cout << "TOTAL time required is: " << time;

}
