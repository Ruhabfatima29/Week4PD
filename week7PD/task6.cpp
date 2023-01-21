#include <iostream>
using namespace std;
void calculatePatients(int);
main()
{
    int days;
    cout << "Enter number of days: ";
    cin >> days;
    calculatePatients(days);
}
void calculatePatients(int day)
{
    int number;
    int treated = 0;
    int untreated=0, untreatedPatients;
    int doctor = 7;
    for (int count = 1; count <= day; count++)
    {
        cout << "Enter value: ";
        cin >> number;
        if(count %3 == 0 && untreated>treated)
        {
         doctor = doctor+1;
        }
        if (number <= doctor)
        {
            treated = treated + number;
        }
        else
        {
            treated = treated + doctor;
            untreatedPatients = number - doctor;
            untreated= untreated+untreatedPatients;
        }
    }
    cout << "Treated patients: " << treated << endl;
    cout << "Untreated patients: " << untreated;
}
