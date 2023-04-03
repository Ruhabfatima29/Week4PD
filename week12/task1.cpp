#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
// function prototypes
void signUp(string, string);
bool signIn(string, string);
void viewUsers();
void storeToFile(string userName, string Password);
bool isValidUserName(string username);
int loginMenu();
void loadDatafromFile();
// global arrays
string userNames[20];
string passwords[20];
int User_count = 0;

main()
{
    loadDatafromFile();
    int choice = 0;
    string name;
    string password;
    while (choice != 4)
    {
        system("cls");
        choice = loginMenu();
        if (choice == 1)
        {
            system("cls");
            // Sign up funtion
            cout << "Enter your Name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            bool check = isValidUserName(name);
            if (check == true)
            {
                signUp(name, password);
                storeToFile(name, password);
                cout << "Signed Successfully";
            }
            else
            {
                cout << "This username already exists. Select a unique identity.... ";
            }
        }
        if (choice == 2)
        {
            // Sign in
            system("cls");
            cout << "Enter your Name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            bool flag = signIn(name, password);
            if (flag == true)
            {
                cout << "Signed in Successfully.." << endl;
            }
            else
            {
                cout << "Invalid Credentials. Sign up First" << endl;
            }
        }
        if (choice == 3)
        {
            // View all users
            system("cls");
            viewUsers();
        }
        // if (choice > 4)
        // {
        //     cout << "You entered invalid option!!! ";
        // }
        getch();
    }
}
int loginMenu()
{
    int choice;
    cout << "1. Sign up " << endl;
    cout << "2. Sign in " << endl;
    cout << "3. View All Users " << endl;
    cout << "4. Exit " << endl;
    cout << " Enter choice: ";
    cin >> choice;
    return choice;
}
void signUp(string username, string password)
{
    userNames[User_count] = username;
    passwords[User_count] = password;
    User_count++;
}
void storeToFile(string userName, string password)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << userName << endl;
    file << password << endl;
    file.close();
}
void viewUsers()
{
    cout << "Username"
         << "\t"
         << "\t"
         << " Password" << endl
         << endl;
    for (int i = 0; i < User_count; i++)
    {
        cout << userNames[i] << "\t\t\t" << passwords[i] << endl;
    }
}
bool signIn(string userName, string Password)
{
    bool check = false;
    for (int i = 0; i < User_count; i++)
    {
        if (userName == userNames[i] && Password == passwords[i])
        {
            check = true;
            break;
        }
    }
    return check;
}
bool isValidUserName(string username)
{
    bool check = true;
    for (int i = 0; i < User_count; i++)
    {
        if (username == userNames[i])
        {
            check = false;
            break;
        }
    }
    return check;
}
void loadDatafromFile()
{
    string password;
    string name;
    fstream file;
    file.open("users.txt", ios::in);
    while (getline(file, name) && getline(file, password))
    {
        userNames[User_count] = name;
        passwords[User_count] = password;
        User_count++;
    }
    file.close();
}