#include<iostream>
#include<cmath>
using namespace std;
main()
{
   float volume , p1 , p2, flowP1, flowP2 , flowRate; 
   float percentFlowrate ;
   float flowRateP1, flowRateP2 ;
   float hours;
   cout << " Enter the volume of  the pool in litres [1 ... 10000] :" ;
   cin  >> volume;
   cout << " Enter the flow rate of first pipe per hour [1...5000] :" ;
   cin  >> p1 ;
   cout << " Enter the flow rate of second pipe per hour [1...5000] :" ;
   cin  >> p2 ; 
   cout << " Enter the hours that the worker was absent for [1.0 .... 24.00] : ";
   cin  >> hours;
   flowRate = (p1 + p2)* hours;
   if( flowRate <= volume)
  {
   flowP1 = p1*hours;
   flowP2 = p2*hours;
   flowRateP1 = (flowP1/flowRate)*100;
   flowRateP2 = (flowP2/flowRate)*100;
   percentFlowrate = (flowRate/volume)*100;
   cout << " The pool is " << percentFlowrate << " % full Pipe1 : " << flowRateP1 << "% Pipe2 : " << flowRateP2 << "%";
  }
  if(flowRate > volume)
  {
   float flowrate = flowRate - volume ; 
   cout << " For " << hours << " hours, the pool overflows with " << flowrate << " litres";
  } 
   
   
}
