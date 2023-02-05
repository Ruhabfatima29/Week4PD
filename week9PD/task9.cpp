#include <iostream>
using namespace std;
main()
{
    string moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "HeadSpin", "Dosado", "Pop", "Lock", "Arabesque"};
    string pin;
    int number, result;
    cout << "Enter pin: ";
    cin >> pin;
    for (int i = 0 ; i < 4  ; i++)
    {

        if (pin[i] == '0' || pin[i] == '1' || pin[i] == '2' || pin[i] == '3' || pin[i] == '4' || pin[i] == '5' || pin[i] == '6' || pin[i] == '7' || pin[i] == '8' || pin[i] == '9')
        {
            if(pin[i] == '0')
            {
                result = 0;
            }
            else if(pin[i] == '1')
            {
                result = 1;
            }
            else if(pin[i] == '2')
            {
                result = 2;
            }
            else if(pin[i] == '3')
            {
                result = 3;
            }
            else if(pin[i] == '4')
            {
                result = 4;
            }
            else if(pin[i] == '5')
            {
                result = 5;
            }
                else if(pin[i] == '6')
            {
                result = 6;
            }
            else if(pin[i] == '7')
            {
                result = 7;
            }
            else if(pin[i] == '8')
            {
                result = 8;
            }
            else if(pin[i] == '9')
            {
                result = 9;
            }
                number = i + result;
                if (number > 9)
                {
                    number = number - 10;
                }
                cout << moves[number] << ",";
            
        }
        else
        {
            cout << "Invalid Input!" << endl;
            break;
        }
    }
}