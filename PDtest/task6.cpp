#include<iostream>
using namespace std;
main()
{
int bagsize;
int bagcost;
float area;
float costperpound;
float costpersqfeet ;
cout << " Enter Bag Size in Pounds : ";
cin  >> bagsize ;
cout << " Enter cost of the bag    : ";
cin  >> bagcost ;
cout << " Enter area covered by each bag in square feet :  ";
cin  >> area;
costperpound = bagcost/bagsize ;
cout << " Cost of the fertilizer per pound: "<< costperpound ;
cout << endl;
costpersqfeet = bagcost/area ;
cout << " Cost of fertilizing the area per square feet: " << costpersqfeet ;
}
