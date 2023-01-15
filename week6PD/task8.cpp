#include <iostream>
using namespace std;
string returnOutput(int, int, int);
main()
{
    int sizeH;
    int x;
    int y;
    string result;
    cout << "Enter size of the block [h] : ";
    cin >> sizeH;
    cout << "Enter x- coordinate : ";
    cin >> x;
    cout << "Enter y-coordinate : ";
    cin >> y;
    result = returnOutput(sizeH, x, y);
    cout << result ;
}
string returnOutput(int h, int x, int y)
{
    string result;
    if ((x >= h * 0 && x < h * 3) && (y == h * 0 || y == h * 1))
    {
        result = "border";
    }
    else if((x == 0 * h || x == 1 * h || x == 2 * h || x == 3 * h)&&(y >= 0 * h && y <= h * 1))
        {
            result = "border";
        }
    else if (((x > 0 * h && x < h * 1) || (x > h * 1 && x < h * 2) || (x > h * 2 && x < h * 3)) &&(y > h * 0 && y < h * 1))
        {
            result = "inside";
        }
    else if( (y >= h*1 && y <= h*4)&&(x==h*1 || x == h*2))
    {
        result = "border";
    }
    else if( (y == h*1 || y == h*2 || y == h*3 || y == h*4) && (x>=h*1 || x<= h*2))
    {
        result = "border";
    }
    else if ((y > h*1 && y < h*2)||(y > h*2 && y< h*3 )||(y > h*3 && y< h*4) && (x > h*1 && x < h*2))
    {
        result = "inside";
    }
    else
    {
        result = "outside";
    }
    return result;
}
