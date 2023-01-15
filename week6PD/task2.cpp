#include<iostream>
using namespace std;
float totalMarks( float, float, float, float, float);
float  returnPercentage(float );
string returnGrade(float);
main()
{
float number1, number2, number3, number4, number5, Marks, percentage;
string name;
string grade;
cout << "Enter your name: ";
cin >> name;
cout << "Enter English marks: ";
cin  >> number1;
cout << "Enter Maths marks: ";
cin  >> number2;
cout << "Enter chemistry marks: ";
cin  >> number3;
cout << "Enter science marks: ";
cin  >> number4;
cout << "Enter biology marks: ";
cin  >> number5;
cout << "Student name is " << name << endl;
Marks = totalMarks(number1,number2,number3,number4,number5);
cout << "Total no. is " << Marks << endl;
percentage= returnPercentage(Marks);
cout << "Percentage is " << percentage <<"%" << endl;
grade = returnGrade(percentage);
cout << "Grade is " << grade << endl ;

}
float totalMarks( float a, float b, float c, float d, float e)
{
float output;
output = a + b + c + d + e;
return output;
}
float percentage(float total)
{
float percent;
percent = (total / 500)*100;
return percent;
}
string  returnGrade(float value)
{
    string grade;
if(value>=90 && value <=100)
{
grade = "A+";
}
if(value>=80 && value <=90)
{
grade = "A";
}
if(value>=70 && value <=80)
{
grade = "B+";
}
if(value>=60 && value <=70)
{
grade = "B";
}
if(value>=50 && value <=60)
{
grade = "C";
}
return grade;
}
float  returnPercentage(float Marks)
{
float total;
total =( Marks/500) *100;
return total;
}