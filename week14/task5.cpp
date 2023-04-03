#include <iostream>
using namespace std;
void rotateArray(int arr[], int size, int position);
main()
{
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    int position;
    cout << "From which position you want to rotate the array: ";
    cin >> position;
    rotateArray(array1, size, position);
     for (int idx = 0; idx < size; idx++)
    {
        cout << array1[idx] << " ";
    }
}
void rotateArray(int arr[], int size, int position)
{
    int idx = size-position;
    
    cout << endl;
    int index = 0;
    for (int idx = position; idx < size; idx++)
    {
        arr[index] = arr[idx];
        index++;
    }
   for(int index= 0; index<position; index++)
    {
    arr[idx] = arr[index];
    idx++; 
    }
   
}