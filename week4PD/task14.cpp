#include<iostream>
using namespace std;
void printMenu();
void compareMarks(string name1 ,int ecatMarks1, string name2, int ecatMarks2);
void calculateAggregate( string name,int matricMarks,int interMarks,int ecatMarks);
main()
{
  int choice;
  int space;
  string name1 , name2;
  int matricMarks1, matricMarks2;
  int interMarks1,  interMarks2;
  int ecatMarks1, ecatMarks2;
  while(true)
 {
  system("cls");
  printMenu();
  cin >> choice;
  system ("cls");
  cout << " You choosed : " << choice << endl ;
  if( choice == 1)
  { 
  cout << " Enter your name : ";
  cin  >> name1 ;
  cout << " Enter your matric marks (out of 1100) : ";
  cin  >> matricMarks1;
  cout << " Enter your inter marks (out of 550) : " ;
  cin  >> interMarks1;
  cout << " Enter your ecat  marks (out of 400) : ";
  cin  >> ecatMarks1 ;
  cout << " Enter any key to continue.....  " << endl;
  cin >> space;
  }
   if(choice == 3)
  {
  calculateAggregate(name1 , matricMarks1, interMarks1, ecatMarks1);
  cout << " Enter any key to continue.....  " << endl;
  cin >> space;
  }
  if( choice == 2)
  { 
  cout << " Enter your name : ";
  cin  >> name2 ;
  cout << " Enter your matric marks (out of 1100) : ";
  cin  >> matricMarks2;
  cout << " Enter your inter marks (out of 550) : " ;
  cin  >> interMarks2;
  cout << " Enter your ecat  marks (out of 400) : ";
  cin  >> ecatMarks2 ;
  cout << " Enter any key to continue.....  " << endl;
  cin >> space;
  }
  if( choice == 4 )
  {
  calculateAggregate(name2 ,matricMarks2,interMarks2 , ecatMarks2);
  cout << endl;
  cout << " Enter any key to continue.....  " << endl;
  cin >> space;
  }
  if( choice == 5 )
  {
  compareMarks(name1 ,ecatMarks1, name2, ecatMarks2);
  cout << endl;
  cout << " Enter any key to continue.....  " << endl;
  cin >> space;
  }
  }
}
void printMenu()
{ 
   cout << " ************************************************** " <<endl;
   cout << " *                      UET                       * " <<endl;
   cout << " *                    LAHORE                      * " <<endl;
   cout << " ************************************************** " <<endl;
   cout << endl << endl;
   cout << " WELCOME TO UET ADMISSION MANAGEMENT SYSTEM ";
   cout << endl << endl ;
   cout << " Press 1 to enter the details of first : " << endl ; 
   cout << " Press 2 to enter the details of second student : " << endl ;
   cout << " Press 3 to calculate the aggregate for the first student : " << endl ;
   cout << " Press 4 to calculate the aggregate for the second student :" << endl ;
   cout << " Enter 5 to display the student with roll no.01 : "<< endl   ;
   cout << " Enter CHOICE: "  ; 

}
void calculateAggregate(string name,int matricMarks,int interMarks,int ecatMarks)
{ 
  system("cls");
  float aggregate = (matricMarks*30)/1100 + (interMarks*30)/550 + (ecatMarks*40)/400;
  cout << " The aggregate of " << name << " is " << aggregate << endl; 
}
void compareMarks(string name1 ,int ecatMarks1, string name2, int ecatMarks2)
{
 if(ecatMarks1 > ecatMarks2)
 {
 cout << " Roll no. 01 is: " << name1 << endl ;
 cout << " Press any key to continue.....";
 }
  if(ecatMarks2 > ecatMarks1)
 {
 cout << " Roll no. 01 is: " << name2 << endl ;
 cout << " Press any key to continue.....";
 }
}

