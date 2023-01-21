#include<iostream>
using namespace std;
void transport(int number);
main()
{
int range;
cout << "Enter range of cargo: ";
cin >> range;
transport(range);

}
void transport(int range)
{
    float number;
    float average,percentMini,percentTruck,percentTrain;
    float total, miniBus=0, truck=0, train=0;
    for(int i=1; i<=range; i++)
    {
    cout <<"Enter number: ";
    cin >> number;
    if( number<=3)
    {
        miniBus=miniBus+number;

    }
    else if( number>3 && number<=11)
    {
        truck=truck+number;
    }
    else
    {
        train=train+number;
    }
    }
    total = miniBus+truck+train;
    average = (miniBus*200+truck*175+train*120)/total;
    cout << average <<"%" << endl;
    percentMini=(miniBus/total)*100;
    cout << percentMini << "%"  << endl;
    percentTruck=(truck/total)*100;
    cout << percentTruck << "%"  << endl;
    percentTrain=(train/total)*100;
    cout << percentTrain << "%"  << endl;

}

