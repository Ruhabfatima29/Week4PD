#include<iostream>
using namespace std;
void merge(int arr1[], int size1, int arr2[], int size2, int arr3[], int size);
main()
{

int numbers1[3] = { 1,4,6};
int size1 = 3;
int numbers2[4] = {7,8,9,0};
int size2 = 4;
int size = size1+size2;
int numbers3[size];
 merge( numbers1, size1, numbers2, size2, numbers3, size);
 for (int index = 0; index<size; index++)
 {
    cout << numbers3[index] << " ";
 }
}
void merge(int arr1[], int size1, int arr2[], int size2, int arr3[], int size)
{
for(int index =0; index<size1; index++)
{
    arr3[index] = arr1[index];
}
for(int index =0; index<size2; index++)
{
    arr3[index+size1] = arr2[index];
}
}