#include <iostream>
using namespace std;
void calculatePercent(int);
main()
{
    int number;
    cout << "Enter any number : ";
    cin >> number;
    calculatePercent(number);
}
void calculatePercent(int number)
{
    float p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
    for (int count = 1; count <= number; count++)
    {
        int number1;
        cout << "Enter value : ";
        cin >> number1;
        if (number1 < 200)
        {
            p1 = p1 + 1;
        }
        else if (number1 >= 200 && number1 < 400)
        {
            p2 = p2 + 1;
        }
        else if (number1 >= 400 && number1 < 600)
        {
            p3 = p3 + 1;
        }
        else if (number1 >= 600 && number1 < 800)
        {
            p4 = p4 + 1;
        }
        else 
        {
            p5 = p5 + 1;
        }
    }
    float p1_percent, p2_percent, p3_percent, p4_percent, p5_percent;
    p1_percent = (p1/number) * 100;
    cout << p1_percent << "%" << endl;
    p2_percent = (p2/number) * 100;
    cout << p2_percent << "%" << endl;
    p3_percent = (p3/number) * 100;
    cout << p3_percent << "%" << endl;
    p4_percent = (p4/number) * 100;
    cout << p4_percent << "%" << endl;
    p5_percent = (p5/number) * 100;
    cout << p5_percent << "%" << endl;
}
