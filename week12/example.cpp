#include<iostream>
#include<fstream>
using namespace std;
main()
{
fstream file;
string line;
int count = 0;
file.open("example.txt", ios::in );
while(!file.eof())
{
count ++;
getline(file,line);
}
cout << "Number of lines is  " << count;
file.close();
}