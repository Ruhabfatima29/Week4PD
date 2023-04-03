#include <iostream>
#include <windows.h>
using namespace std;
void displayWorld();
void setGravityStatus(bool value);
void timeTick(int times);
char objects[5][5] = {
    {'-', '#', '#', '-', '#'},

    {'#', '-', '-', '#', '-'},

    {'-', '#', '-', '-', '-'},

    {'#', '-', '#', '-', '#'},

    {'#', '-', '-', '-', '-'}

};
bool gravity = false;
bool blackHole = true;
main()
{
    displayWorld();
    setGravityStatus(true);
    timeTick(3);
    displayWorld();
}
void displayWorld()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << objects[row][col];
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void setGravityStatus(bool value)
{
    gravity = value;
}
// void timeTick(int times)
// {
//     int count = 0;
//     if (gravity)
//     {
//         while (count < times)
//         {
//             for (int row = 4; row >= 0; row--)
//             {
//                 for (int col = 0; col < 5; col++)
//                 {
//                     if (objects[row][col] == '#')
//                     {
//                         if (objects[row + 1][col] == '-')
//                         {
//                             objects[row + 1][col] = '#';
//                             objects[row][col] = '-';
//                         }
//                     }
//                      if (blackHole && objects[row][col] == '#')
//                     {
//                         if (row == 4 && objects[0][col] == '-') // check if object is on last row
//                         {
//                             objects[0][col] = '#'; // move object to first row
//                             objects[row][col] = '-';
//                         }
                        
//                     }
//                 }
//             }
//             count = count + 1;
//         }
//     }
// }
void timeTick(int times)
{
    int count = 0;
    if (gravity)
    {
        while (count < times)
        {
            for (int row = 4; row >= 0; row--)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (objects[row][col] == '#')
                    {
                        if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                }
            }
            if (blackHole && objects[4][0] == '#' && objects[4][1] == '#' && objects[4][2] == '#' && objects[4][3] == '#' && objects[4][4] == '#')
            {
                for (int col = 0; col < 5; col++)
                {
                    objects[0][col] = objects[4][col];
                    objects[4][col] = '-';
                }
            }
            count = count + 1;
        }
    }
}
