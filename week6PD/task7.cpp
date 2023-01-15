#include <iostream>
using namespace std;
string returnTime(int, int, int, int);
main()

{
    int examH, arrivalH, examM, arrivalM;
    string output;
    cout << "Enter the exam starting hour : ";
    cin >> examH;
    cout << "Enter the exam starting minutes : ";
    cin >> examM;
    cout << "Enter your arrival time [h] : ";
    cin >> arrivalH;
    cout << "Enter your arrival time [m] : ";
    cin >> arrivalM;
    output = returnTime(examH, examM, arrivalH, arrivalM);
    cout << output << endl;
    if(output == "On time"  && examM != arrivalM)
    {
    if(arrivalM <=30)
    {
    cout << arrivalM- examM << " minutes before the start ";
    }
    else if(arrivalM > 30)
    {
    cout << 60 - arrivalM<< "minutes before the start ";
    }
    }
    if(output == "Late")
    {
    if(examH == arrivalH)
    {
        cout << arrivalM - examM << " minutes after the start ";
    }
   else if(arrivalH > examH)
    {
    cout << arrivalH - examH << ":" << arrivalM - examM << "hours after the start " ;
    }
    }
   if(output == "Early")
   {
   if(arrivalH == examH-1 && examM < arrivalM)
   {
    cout << (examM+60)- arrivalM << " minutes before the start";
   }
  else
  {
   cout << examH - arrivalH << ":" << examM- arrivalM << "hours before the start ";

  }

   }

}
string returnTime(int examH, int examM, int arrivalH, int arrivalM)
{
    string time;
    if ((examH == arrivalH && examM == arrivalM))
    {
        time = "On time";
    }
    else if (((examH - 1) == arrivalH && ( (arrivalM-30) >= examM ) )|| ((examH == arrivalH) && (examM > arrivalM)))
    {
        time = "On time";
    }
    else if(examH == arrivalH && arrivalM > examM || (arrivalH > examH))
    {
      time = "Late";  
    }
    else if(arrivalH < examH || (examH==arrivalH)&&((examM-30)>arrivalM))
    {
      time = "Early";
    }    
return time;
}