#include<iostream>
#include<cmath>
using namespace std;
int time( int days, int workers );
main()
{
  int hours;
  int days;
  int workers;
  int final;
  int result;
  cout << " Enter hours needed to complete project : ";
  cin  >> hours;
  cout << " Enter no. of days to complete project : ";
  cin  >> days;
  cout << " Enter no. of workers : ";
  cin  >> workers;
  final = time (  days , workers);
  if (final > hours )
  {
  result = final - hours;
  cout << " Yes! " << result << " hours left.";
  }
  if (final < hours)
  {
  result = hours - final;
  cout << " Not enough time! " << result << " hours needed ";
  }
}
int time(int days, int workers)
{
  float workingDays;
  float totalHours;
  int totalTime;
  float final;
  workingDays = days - (days*0.1);
  totalHours = workingDays*10;
  final = floor(totalHours);
  totalTime = final*workers;
  return totalTime;

}