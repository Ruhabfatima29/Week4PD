#include <iostream>
using namespace std;
char returnGrade(int number);
main()
{
    char result;
    int numbers;
    cout << " Enter numbers : ";
    cin >> numbers;
    result = returnGrade(numbers);
    cout << " GRADE IS : " << result;
}
char returnGrade(int number)
{
    char grade;
    if (number < 50)
    {
        grade = 'F';
    }
    else if (number >= 50 && number <= 60)
    {
        grade ='E';
    }
    else if (number > 60 && number <= 70)
    {
        grade = 'D';
    }
    else if (number > 70 && number <= 80)
    {
        grade = 'C';
    }
    else if (number > 80 && number <= 85)
    {
        grade = 'B';
    }
    else if ( number > 85)
    {
        grade = 'A';
    }
    else
    {
        grade = '0';
    }
    return grade;
}


