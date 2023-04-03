#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;
// Global arrays for sign in and sign up
string names[100] = {"Ali", "Sana"};
string passwords[100] = {"1111", "2222"};
string roles[100] = {"Admin", "User"};
int counter = 2;

// Global arrays for adding parties
string parties[20];
string symbols[20];
string founders[20];
int parties_counter[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int adminCount = 0;

// Global arrays for adding polling station
string Ps_names[20];
string Ps_codes[20];
string areas[20];
int Ps_counter = 0;

// Global arrays for vote casting
string voters[100];
string cnics[100];
string votes[100];
string feedbacks[100];
int voters_count = 0;
// function prototypes
void printHeader();
// login Helping functions
string loginMenu();
void signUp(string name, string pass, string role);
bool isValidUserName(string password, string name);
void storeToLoginFile(string userName, string password, string role);
void loadDatafromLoginFile();
string parseData(string line, int field);
void viewUsers();
string signIn();
// this function is used to check whether the data entered is integer or not
bool checkValidInputOption(string);

bool validSymbol(string symbol);
bool validFounder(string founder);
void subMenuBeforeMainMenu(string submenu);
void subMenu(string submenu);
void printMenu();
// Admin functions
void adminInterface();
void printAdminMenu();
string AdminMenu();
void addParty();
void storeToElectedPartiesFile(string partyName, string symbol, string founder, int party_counter);
void loadDatafromElectedPartiesfile();
void delParty();
void updatedElectedPartyFile();
void searchParty();
void viewParties();
void updateParties_counter(string voted_party);
void AddPs(string Ps_name, string Ps_code, string area);
void storeToPsFile(string Ps_name, string Ps_code, string area);
void loadDatafromPSfile();
void del_Ps(int index);
void updatedPsfile();
bool validPS(string Ps_name, string Ps_code);
void view_Ps();
void search_Ps();
void update_Ps();
void update_Party();
void adminFunctions();
void votersDetails();
void storeToVotersDetailsFile(string voter, string cnic, string voted_party, string feedback);
void loadFromVotersDetailsFile();
void updatedVotersFile();
void search_response();
void declare_result();
void viewfeedback();
// this funtion is used to check that given data contains alphabets and space only
bool validUserNameData(string name);
// User functions
void printUserMenu();
string userMenu();
void userInterface();
void userFunctions();
void castVote();
bool validCnic(string cnic);
bool checkSelectedValidElectedParty(string voted_party);
bool checkIsValidVoter(string voter, string cnic);
void viewResponse();
void updateResponse();
void voter_feedbacks();
void vote_status();
// Function definitions
main()
{
    loadDatafromLoginFile();
    loadDatafromPSfile();
    loadFromVotersDetailsFile();
    loadDatafromElectedPartiesfile();
    string option = "0";
    bool check;
    system("cls");
    printHeader();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    while (option != "3")
    {
        system("cls");
        printHeader();
        subMenu("");
        cout << "Select an option from the given menu " << endl;
        option = loginMenu();
        check = checkValidInputOption(option);
        if (check == false)
        {
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << " Invalid input ): " << endl;
        }
        else
        {
            if (option == "1")
            {
                system("cls");
                printHeader();
                subMenu(" SignUp menu");
                // SIGN Up
                string name, pass, role;
                bool isvalidName;
                cin.ignore(356, '\n');
                cout << "Enter Name[informat i.e. Alyan]: ";
                getline(cin, name);
                isvalidName = validUserNameData(name);
                while (isvalidName == false)
                {
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Invalid name " << endl;
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "Enter Name[informat i.e. Alyan]: ";
                    getline(cin, name);
                    isvalidName = validUserNameData(name);
                }
                cout << "<Your Password must be 4 character long>" << endl;
                cout << "Enter Password: ";
                cin >> pass;
                int size = pass.length();
                while (size != 4)
                {
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Invalid password " << endl;
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "Enter Password: ";
                    cin >> pass;
                    size = pass.length();
                }
                cout << "Enter your Role[Admin,User]: ";
                cin >> role;
                while (role != "Admin" && role != "User")
                {
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << " Invalid role entered" << endl;
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "Enter your Role[Admin,User]: ";
                    cin >> role;
                }
                bool check = isValidUserName(pass, name);
                if (check == true)
                {
                    signUp(name, pass, role);
                    storeToLoginFile(name, pass, role);
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << endl
                         << "<<< Remember that login name and password in order to sign in with that account >>>" << endl;
                    cout << endl
                         << " SIGNED UP SUCCESSFULLY !!!" << endl;
                }
                else
                {
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << endl
                         << "User and password is already found. Kindly sign up with new ID (: " << endl;
                }
            }
            else if (option == "2")
            {
                system("cls");
                printHeader();
                subMenu(" SignIn menu");
                // SIGN IN
                string choice;
                choice = signIn();
                if (choice == "No")
                {
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << endl
                         << "NO User Found!!!! Sign up First..." << endl;
                }
                else if (choice == "Admin")
                {

                    system("cls");
                    // Admin Menu
                    adminFunctions();
                }
                else
                {
                    system("cls");
                    // User Menu
                    userFunctions();
                }
            }
            else if (option != "1" && option != "2" && option != "3")
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << " Invalid input ): " << endl;
            }
            cout << endl
                 << "Press any key to continue..." << endl;
            Sleep(100);
            getch();
        }
    }
}
void printHeader()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "||*************************************************************************************||" << endl;
    cout << "||";
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "**************************ELECTION VOTING MANAGEMENT SYSTEM**************************";
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "||" << endl;
    cout << "||*************************************************************************************||" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "<>        The Ignorance of one voter in a democracy impairs the security of all       <> " << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "_________________________________________________________________________________________" << endl;
    printMenu();
}
bool checkValidInputOption(string option)
{
    bool flag;
    int size = option.length();
    for (int idx = 0; idx < size; idx++)
    {
        if (option[idx] >= 48 && option[idx] <= 57)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool validUserNameData(string name)
{
    bool flag;
    int size = name.length();
    for (int idx = 0; idx < size; idx++)
    {
        if ((name[idx] >= 65 && name[idx] <= 90) || (name[idx] >= 97 && name[idx] <= 122) || name[idx] == 32)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
string loginMenu()
{
    string option;
    cout << "1. Sign up: " << endl;
    cout << "2. Sign in: " << endl;
    cout << "3. Exit: " << endl;
    cout << "Enter your option: ";
    cin >> option;
    return option;
}
void signUp(string name, string pass, string role)
{
    names[counter] = name;
    passwords[counter] = pass;
    roles[counter] = role;
    counter++;
}
bool isValidUserName(string pass, string name)
{
    bool check = true;

    for (int i = 0; i < counter; i++)
    {
        if (name == names[i] && pass == passwords[i])
        {
            check = false;
            break;
        }
    }
    return check;
}
void storeToLoginFile(string userName, string password, string role)
{
    fstream file;
    file.open("loginFile.txt", ios::app);
    file << userName << ",";
    file << password << ",";
    file << role << endl;
    file.close();
}
void loadDatafromLoginFile()
{
    fstream file;
    string line;
    file.open("loginFile.txt", ios::in);
    while (getline(file, line))
    {
        names[counter] = parseData(line, 1);
        passwords[counter] = parseData(line, 2);
        roles[counter] = parseData(line, 3);
        counter++;
    }
    file.close();
}
string parseData(string line, int field)
{
    int commaCount = 1;
    string item = "";
    int length = line.length();
    for (int idx = 0; idx < length; idx++)
    {
        if (line[idx] == ',')
        {
            commaCount++;
        }
        else if (field == commaCount)
        {
            item = item + line[idx];
        }
    }
    return item;
}

string signIn()
{
    string name, password;
    cin.ignore(356,'\n');
    cout << "Enter Name: ";
    getline(cin,name);
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < counter; i++)
    {
        if (name == names[i] && password == passwords[i])
            return roles[i];
    }
    return "No";
}
void printMenu()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^                                    MAIN MENU                                     ^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void printAdminMenu()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "&&                     ADMIN'S INTERFACE                      &&" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl
         << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "1.  Add elective parties: " << endl;
    cout << "2.  Delete elective parties: " << endl;
    cout << "3.  Search for an elective party: " << endl;
    cout << "4.  View all the parties: " << endl;
    cout << "5.  Add polling stations: " << endl;
    cout << "6.  Delete polling stations: " << endl;
    cout << "7.  Update polling stations: " << endl;
    cout << "8.  Search for a polling station: " << endl;
    cout << "9.  View all polling stations: " << endl;
    cout << "10. Update elective party:  " << endl;
    cout << "11. View all details of the voters: " << endl;
    cout << "12. Search for the response of the voter: " << endl;
    cout << "13. Declare the election results: " << endl;
    cout << "14. View the feedback of the voters: " << endl;
    cout << "15. View all the Accounts details: " << endl;
    cout << "16. Exit " << endl
         << endl;
    cout << "Enter your response: ";
}
string AdminMenu()
{
    string option;
    printAdminMenu();
    cin >> option;
    return option;
}
void viewUsers()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\tUsername"
         << "\t"
         << "\t"
         << " Password"
         << "\t"
         << "\t"
         << " Roles" << endl
         << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 0; i < counter; i++)
    {
        cout << setw(15) << names[i] << setw(25) << passwords[i] << setw(22) << roles[i] << endl;
    }
}
void adminInterface()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "&&                                 ADMIN'S INTERFACE                                        &&" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "&&  Democracy is not just a right to vote but it is a right to select to live with Dignity &&" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl
         << endl;
}
void subMenuBeforeMainMenu(string submenu)
{
    string statement = submenu + " Menu";
    cout << statement << endl;
    cout << "=====================================================================================" << endl;
}
void subMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "_____________________________________________________________________________________" << endl
         << endl;
}
void adminFunctions()
{
    printAdminMenu();
    subMenu(" SignIn menu > Admin menu");
    string choice = "0";
    bool check;
    while (choice != "16")
    {
        system("cls");
        choice = AdminMenu();
        check = checkValidInputOption(choice);
        if (check == false)
        {
            cout << "Invalid Option" << endl;
            getch();
        }
        else
        {
            if (choice == "1")
            {
                // Adding a party
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Add a party");
                cout << "You Choosed: " << choice << endl
                     << endl;
                addParty();
            }
            else if (choice == "2")
            {

                // Deleting a party
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Delete a party");
                cout << "You Choosed: " << choice << endl
                     << endl;
                delParty();
            }
            else if (choice == "3")
            {
                // Search for an party
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Search a party");
                cout << "You Choosed: " << choice << endl
                     << endl;
                searchParty();
            }
            else if (choice == "4")
            {
                // View all the Parties
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > View all party");
                cout << "You Choosed: " << choice << endl
                     << endl;
                viewParties();
            }
            else if (choice == "5")
            {
                // add polling stations
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Add polling station");
                cout << "You Choosed: " << choice << endl
                     << endl;
                string Ps_name, Ps_code, area;
                string flag = "false";
                bool validPsName, validArea;
                cout << "************* ADD POLLING STATIONS ************" << endl
                     << endl;
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cin.ignore(356, '\n');
                cout << "Enter the polling station name : ";
                getline(cin, Ps_name);
                validPsName = validUserNameData(Ps_name);
                while (validPsName == false)
                {
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "Invalid Input" << endl;
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Enter the polling station name : ";
                    getline(cin, Ps_name);
                    validPsName = validUserNameData(Ps_name);
                }
                cout << "Enter the code of the polling station: ";
                getline(cin, Ps_code);
                cout << "Enter the area of the polling station: ";
                getline(cin, area);
                validArea = validUserNameData(area);
                while (validArea == false)
                {
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "Invalid Input" << endl;
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Enter the area of the polling station: ";
                    getline(cin, area);
                    validArea = validUserNameData(area);
                }
                bool check = validPS(Ps_name, Ps_code);
                if (check == true)
                {
                    AddPs(Ps_name, Ps_code, area);
                    storeToPsFile(Ps_name, Ps_code, area);
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << endl
                         << "Polling station added Successfully !!! ";
                }
                else
                {

                    cout << endl
                         << "Polling Station ALREADY EXISTS!!! " << endl;
                }
            }
            else if (choice == "6")
            {
                // delete polling station
                system("cls");
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Delete polling station");
                cout << "You Choosed: " << choice << endl
                     << endl;
                string delPs;
                cin.ignore(356, '\n');
                cout << "Enter the name of the Polling station you want to delete: ";
                getline(cin, delPs);
                int index;
                bool check = false;
                for (int idx = 0; idx < Ps_counter; idx++)
                {
                    if (Ps_names[idx] == delPs)
                    {
                        check = true;
                        index = idx;
                        break;
                    }
                }
                if (check == true)
                {
                    del_Ps(index);
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Polling station " << delPs << " is deleted successfully. " << endl;
                    updatedPsfile();
                }
                else
                {
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << "Polling station not found." << endl;
                }
            }
            else if (choice == "7")
            {
                // update polling stations
                subMenu(" SignIn menu > Admin menu > Update polling station");
                system("cls");
                adminInterface();
                cout << "You Choosed: " << choice << endl
                     << endl;
                update_Ps();
            }
            else if (choice == "8")
            {
                // search polling stations
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Search polling station");
                cout << "You Choosed: " << choice << endl
                     << endl;
                search_Ps();
            }
            else if (choice == "9")
            {
                // View all polling stations
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > View all polling station");
                cout << "You Choosed: " << choice << endl
                     << endl;
                view_Ps();
            }
            else if (choice == "10")
            {
                // update elective party
                subMenu(" SignIn menu > Admin menu > Update elective Party");
                system("cls");
                adminInterface();
                cout << "You Choosed: " << choice << endl
                     << endl;
                update_Party();
            }
            else if (choice == "11")
            {
                // View all details of voters
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > View voters details");
                cout << "You Choosed: " << choice << endl
                     << endl;
                votersDetails();
            }
            else if (choice == "12")
            {
                // Search for response of the voter
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Search voter response");
                cout << "You Choosed: " << choice << endl
                     << endl;
                search_response();
            }
            else if (choice == "13")
            {
                // Declaration of results
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > Election Results");
                cout << "You Choosed: " << choice << endl
                     << endl;
                declare_result();
            }
            else if (choice == "14")
            {
                // Feedback of voters
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > View Voters Feedback");
                cout << "You Choosed: " << choice << endl
                     << endl;
                viewfeedback();
            }
            else if (choice == "15")
            {
                // View all the users
                system("cls");
                adminInterface();
                subMenu(" SignIn menu > Admin menu > View all Accounts");
                cout << "You Choosed: " << choice << endl
                     << endl;
                viewUsers();
            }
            else if (choice != "16")
            {
                cout << "Invalid Input " << endl;
            }
            Sleep(100);
            getch();
        }
    }
}
void addParty()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    string partyName, partySymbol, founder;
    string flag = "false";
    bool isvalidSymbol, isValidFounder, checkFounderData, checkPartyData;
    cout << "########### ADD ELECTIVE Parties ##########" << endl;
    cin.ignore(356, '\n');
    cout << " Enter the name of The Elected Party: ";
    getline(cin, partyName);
    // checks validity of Elected party's data
    checkPartyData = validUserNameData(partyName);
    while (checkPartyData == false)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Invalid data entered..." << endl;
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " Enter the name of The Elected Party: ";
        getline(cin, partyName);
        checkPartyData = validUserNameData(partyName);
    }
    cout << " Enter the Symbol of your Elected Party: ";
    getline(cin, partySymbol);
    // checks the validity of symbol's data
    isvalidSymbol = validSymbol(partySymbol);
    while (isvalidSymbol == false)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Invalid Symbol. This symbol is already allocated to another party.." << endl;
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " Enter the Symbol of your Elected Party: ";
        getline(cin, partySymbol);
        isvalidSymbol = validSymbol(partySymbol);
    }
    cout << " Enter the name of the founder of Elected Party:  ";
    getline(cin, founder);
    checkFounderData = validUserNameData(founder);
    // checks the validity of founder's data
    isValidFounder = validFounder(founder);
    while (isValidFounder == false || checkFounderData == false)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        if (isValidFounder == false)
        {
            cout << "Invalid Founder. For two different parties, there couldn't be a same founder." << endl;
        }
        else
        {
            cout << "Invalid data entered. You can only enter alphabets and spaces." << endl;
        }
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " Enter the name of the founder of Elected Party:  ";
        getline(cin, founder);
        isValidFounder = validFounder(founder);
        checkFounderData = validUserNameData(founder);
    }
    for (int i = 0; i < adminCount; i++)
    {
        if (partyName == parties[i] || founder == founders[i])
        {
            flag = "true";
            break;
        }
    }
    if (flag == "true")
    {
        cout << "PARTY ALREADY EXISTS!!! " << endl;
    }
    else
    {
        int party_votes;
        parties[adminCount] = partyName;
        founders[adminCount] = founder;
        symbols[adminCount] = partySymbol;
        party_votes = parties_counter[adminCount];
        adminCount++;
        cout << endl
             << "<<<Party added Successfully>>>" << endl;
        storeToElectedPartiesFile(partyName, partySymbol, founder, party_votes);
    }
}
bool validSymbol(string symbol)
{
    bool flag = true;
    for (int i = 0; i < adminCount; i++)
    {
        if (symbol == symbols[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void storeToElectedPartiesFile(string partyName, string symbol, string founder, int votes_counter)
{
    fstream file;
    file.open("ElectedParties.txt", ios::app);
    file << partyName << ",";
    file << symbol << ",";
    file << founder << ",";
    file << votes_counter << endl;
    file.close();
}
void loadDatafromElectedPartiesfile()
{
    fstream file;
    string line;
    file.open("ElectedParties.txt", ios::in);
    while (getline(file, line))
    {
        parties[adminCount] = parseData(line, 1);
        symbols[adminCount] = parseData(line, 2);
        founders[adminCount] = parseData(line, 3);
        parties_counter[adminCount] = stoi(parseData(line, 4));
        adminCount++;
    }

    file.close();
}
void delParty()
{
    string del_party;
    int place;
    bool flag = false;
    cin.ignore(356, '\n');
    cout << "Enter the name of the party you want to delete: ";
    getline(cin, del_party);
    for (int index = 0; index < adminCount; index++)
    {
        if (del_party == parties[index])
        {
            flag = true;
            place = index;
            break;
        }
    }
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (flag == true)
    {
        for (int index = place; index < adminCount; index++)
        {
            parties[index] = parties[index + 1];
            founders[index] = founders[index + 1];
            symbols[index] = symbols[index + 1];
            parties_counter[index] = parties_counter[index + 1];
        }
        adminCount--;
        updatedElectedPartyFile();
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << del_party << " is deleted successfully. " << endl;
    }
    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Party of this name is not Found.." << endl;
    }
}
void updatedElectedPartyFile()
{
    fstream file;
    file.open("ElectedParties.txt", ios::out);
    for (int idx = 0; idx < adminCount; idx++)
    {
        file << parties[idx] << ",";
        file << symbols[idx] << ",";
        file << founders[idx] << ",";
        file << parties_counter[idx] << endl;
    }
    file.close();
}
void searchParty()
{
    string srch_party;
    cin.ignore(356, '\n');
    cout << "Enter the name of the party you want to search: ";
    getline(cin, srch_party);
    bool flag = false;
    int place;
    for (int index = 0; index < adminCount; index++)
    {
        if (srch_party == parties[index])
        {
            flag = true;
            place = index;
            break;
        }
    }
    if (flag == true)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " YOU searched for the party " << srch_party << endl;
        cout << " The symbol of this party is " << symbols[place] << endl;
        cout << " The founder of this party is  " << founders[place] << endl;
    }
    else
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "This party not found..." << endl;
    }
}
void AddPs(string Ps_name, string Ps_code, string area)
{
    // function of adding polling station

    Ps_names[Ps_counter] = Ps_name;
    Ps_codes[Ps_counter] = Ps_code;
    areas[Ps_counter] = area;
    Ps_counter++;
}
bool validPS(string Ps_name, string Ps_code)
{
    bool flag = true;
    for (int index = 0; index < Ps_counter; index++)
    {
        if (Ps_name == Ps_names[index] && Ps_code == Ps_codes[index])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool validFounder(string founder)
{
    bool check = true;
    for (int index = 0; index < Ps_counter; index++)
    {
        if (founder == founders[index])
        {
            check = false;
            break;
        }
    }
    return check;
}
void storeToPsFile(string Ps_name, string Ps_code, string area)
{
    fstream file;
    file.open("PSfile.txt", ios::app);
    file << Ps_name << ",";
    file << Ps_code << ",";
    file << area << endl;
    file.close();
}
void loadDatafromPSfile()
{
    fstream file;
    string line;
    file.open("PSfile.txt", ios::in);
    while (getline(file, line))
    {
        Ps_names[Ps_counter] = parseData(line, 1);
        Ps_codes[Ps_counter] = parseData(line, 2);
        areas[Ps_counter] = parseData(line, 3);
        Ps_counter++;
    }
    file.close();
}
void viewParties()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    cout << "\t Elected Parties \t      Symbols\t\t\tFounder " << endl
         << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

    for (int i = 0; i < adminCount; i++)
    {
        cout << setw(20) << parties[i] << setw(25) << symbols[i] << setw(30) << founders[i] << endl;
    }
}
void del_Ps(int index)
{
    for (int idx = index; idx < Ps_counter; idx++)
    {
        Ps_names[idx] = Ps_names[idx + 1];
        Ps_codes[idx] = Ps_codes[idx + 1];
        areas[idx] = areas[idx + 1];
    }
    Ps_counter--;
}
void updatedPsfile()
{

    fstream file;
    file.open("PSfile.txt", ios::out);
    for (int idx = 0; idx < Ps_counter; idx++)
    {
        file << Ps_names[idx] << ",";
        file << Ps_codes[idx] << ",";
        file << areas[idx] << endl;
    }
    file.close();
}
void view_Ps()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t PS_Names   "
         << " \t\t\t "
         << " PS_codes  "
         << " \t\t"
         << "   Areas " << endl
         << endl;
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    for (int i = 0; i < Ps_counter; i++)
    {
        if (Ps_names[i] == "")
        {
            continue;
        }
        cout << setw(25) << Ps_names[i] << setw(25) << Ps_codes[i] << setw(25) << areas[i] << endl;
    }
}
void search_Ps()
{
    string srch_Ps;
    cin.ignore(356, '\n');
    cout << "Enter the name of the Polling station you want to search: ";
    getline(cin, srch_Ps);
    bool flag = false;
    int place;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int index = 0; index < Ps_counter; index++)
    {
        if (srch_Ps == Ps_names[index])
        {
            flag = true;
            place = index;
            break;
        }
    }
    if (flag == true)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " You searched for the polling station " << srch_Ps << endl;
        cout << " The code of this polling station is " << Ps_codes[place] << endl;
        cout << " The area of this polling station is  " << areas[place] << endl;
    }
    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "The polling station not found..." << endl;
    }
}
void update_Ps()
{
    string update_Ps, updated_name, updated_code, updated_area;
    bool flag = false;
    int place;
    cin.ignore(356, '\n');
    cout << " Enter the code of the polling station you want to update: ";
    getline(cin, update_Ps);
    for (int i = 0; i < Ps_counter; i++)
    {
        if (update_Ps == Ps_names[i])
        {
            flag = true;
            place = i;
            break;
        }
    }
    if (flag == true)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << " Enter the updated name of polling station: ";
        getline(cin, updated_name);
        cout << " Enter the updated code of the polling station: ";
        getline(cin, updated_code);
        cout << " Enter the updated area of the polling station: ";
        getline(cin, updated_area);
        Ps_names[place] = updated_name;
        Ps_codes[place] = updated_code;
        areas[place] = updated_area;
        updatedPsfile();
        cout << "Updated Successfully !!!" << endl;
    }
    else
    {
        cout << "Polling station not found ): " << endl;
    }
}
void update_Party()
{
    string party, updated_name, updated_symbol, updated_founder;
    bool flag = false;
    int place;
    cin.ignore(356, '\n');
    cout << " Enter the name of the elected party you want to update: ";
    getline(cin, party);
    for (int i = 0; i < adminCount; i++)
    {
        if (party == parties[i])
        {
            flag = true;
            place = i;
            break;
        }
    }
    if (flag == true)
    {
        cout << " Enter the updated name of elected party: ";
        getline(cin, updated_name);
        cout << " Enter the updated symbol of the elected party: ";
        getline(cin, updated_symbol);
        cout << " Enter the updated founder of the elected party: ";
        getline(cin, updated_founder);
        parties[place] = updated_name;
        symbols[place] = updated_symbol;
        founders[place] = updated_founder;
        updatedElectedPartyFile();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << endl
             << endl
             << "Updated Successfully !!!" << endl;
    }
    else
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << endl
             << endl
             << "Elected Party not found ): " << endl;
    }
}
void printUserMenu()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "<>                               USER'S INTERFACE                                 <>" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "<>           BAD OFFICIALS ARE ELECTED BY GOOD CITIZENS WHO DON'T VOTE            <>" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl
         << endl
         << endl;
    subMenu(" SignIn menu > User menu");
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "1. View all polling stations: " << endl;
    cout << "2. Search your polling station: " << endl;
    cout << "3. View all the Elected Parties: " << endl;
    cout << "4. Search an elected party: " << endl;
    cout << "5. Cast your vote: " << endl;
    cout << "6. View your respose: " << endl;
    cout << "7. Update your profile data: " << endl;
    cout << "8. Give your feedback: " << endl;
    cout << "9. Check your (vote)status:" << endl;
    cout << "10.Exit: " << endl
         << endl
         << endl;
    cout << "   Enter your response: ";
}
string userMenu()
{
    string option;
    printUserMenu();
    cin >> option;
    return option;
}
void userInterface()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "<>                                 USER'S INTERFACE                                        <>" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "<>               BAD OFFICIALS ARE ELECTED BY GOOD CITIZENS WHO DON'T VOTE                 <>" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl
         << endl
         << endl;
}
void userFunctions()
{

    string option = "0";
    bool check;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printUserMenu();
    while (option != "10")
    {
        system("cls");
        option = userMenu();
        check = checkValidInputOption(option);
        if (check == false)
        {
            cout << "Invalid Option" << endl;
            getch();
        }
        else
        {
            if (option == "1")
            {
                // view polling stations
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > View Polling stations");
                view_Ps();
            }
            else if (option == "2")
            {
                // search polling stations
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Search Polling stations");
                search_Ps();
            }
            else if (option == "3")
            {
                // view parties
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > View Elected Parties");
                viewParties();
            }
            else if (option == "4")
            {
                // search a party
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Search Elected Parties");
                searchParty();
            }
            else if (option == "5")
            {
                // cast vote
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Cast Vote");
                castVote();
            }
            else if (option == "6")
            {
                // View response
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > View your response");
                viewResponse();
            }
            else if (option == "7")
            {
                // Update response
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Update your response");
                updateResponse();
            }
            else if (option == "8")
            {
                // Enter feedbacks
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Give your feedback");
                cout << "     Voters Feedback. " << endl;
                voter_feedbacks();
            }
            else if (option == "9")
            {
                // Check vote status
                system("cls");
                userInterface();
                subMenu(" SignIn menu > User menu > Check your vote status");
                vote_status();
            }
            else if (option != "10")
            {
                cout << "Invalid Input " << endl;
            }
            Sleep(100);
            getch();
        }
    }
}
void castVote()
{
    viewParties();
    cout << endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string voter, cnic;
    bool validVoterData, isValidCnic;
    cin.ignore(356, '\n');
    cout << " Enter your name: ";
    getline(cin, voter);
    validVoterData = validUserNameData(voter);
    while (validVoterData == false)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Invalid Input " << endl;
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " Enter your name: ";
        getline(cin, voter);
        validVoterData = validUserNameData(voter);
    }
    cout << " Enter your CNIC number: ";
    getline(cin, cnic);
   
    isValidCnic = validCnic(cnic);
    while(isValidCnic == false) 
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Invalid Input " << endl;
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " Enter your CNIC number in proper format i.e. XXXXX-XXXXXXX-X " << endl;
        cout << " Enter your CNIC number: ";
        getline(cin, cnic);
        isValidCnic = validCnic(cnic);
    }
    bool flag = checkIsValidVoter(voter, cnic);
    if (flag == false)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "The person with this ID has already voted!!! " << endl;
    }
    else
    {
        string voted_party;
        cout << "Enter the name of the party you want to vote: ";
        getline(cin, voted_party);
        bool check = checkSelectedValidElectedParty(voted_party);
        if (check == true)
        {
            // Stores vote in arrays
            votes[voters_count] = voted_party;
            voters[voters_count] = voter;
            cnics[voters_count] = cnic;
            feedbacks[voters_count] = " not feedbacked yet...";
            updateParties_counter(voted_party);
            storeToVotersDetailsFile(voter, cnic, voted_party, feedbacks[voters_count]);
            voters_count++;
            updatedElectedPartyFile();
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Voted Successfully..." << endl;
        }
        else
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << endl
                 << "You selected an undefined party. Please vote from the given elected parties." << endl;
            cout << "To view the list of all elective parties,select option 3... " << endl;
        }
    }
}
void updateParties_counter(string voted_party)
{
    for (int idx = 0; idx < adminCount; idx++)
    {
        if (voted_party == parties[idx])
        {
            parties_counter[idx] = parties_counter[idx] + 1;
            break;
        }
    }
}
bool checkIsValidVoter(string voter, string cnic)
{
    bool flag = true;
    for (int i = 0; i < voters_count; i++)
    {
        if (voter == voters[i] && cnic == cnics[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool checkSelectedValidElectedParty(string voted_party)
{
    bool flag = false;
    for (int idx = 0; idx < adminCount; idx++)
    {
        if (voted_party == parties[idx])
        {
            // parties_counter[idx]++;
            flag = true;
            break;
        }
    }
    return flag;
}
void storeToVotersDetailsFile(string voter, string cnic, string voted_party, string feedback)
{
    fstream file;
    file.open("VotersDetails.txt", ios::app);
    file << voter << ",";
    file << cnic << ",";
    file << voted_party << ",";
    file << feedback << endl;
    file.close();
}
void loadFromVotersDetailsFile()
{
    fstream file;
    string line;
    file.open("VotersDetails.txt", ios::in);
    while (getline(file, line))
    {
        voters[voters_count] = parseData(line, 1);
        cnics[voters_count] = parseData(line, 2);
        votes[voters_count] = parseData(line, 3);
        // updateParties_counter(votes[voters_count]);
        feedbacks[voters_count] = parseData(line, 4);
        voters_count++;
    }
    file.close();
}
void viewResponse()
{
    string name;
    int place;
    bool flag = false;
    cin.ignore(356, '\n');
    cout << "Enter your name to see your response: ";
    getline(cin, name);
    for (int i = 0; i < voters_count; i++)
    {
        if (name == voters[i])
        {
            flag = true;
            place = i;
        }
    }
    if (flag == true)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Your name is " << name << endl;
        cout << "Your cnic number is " << cnics[place] << endl;
        cout << "You voted for " << votes[place] << endl;
    }
    else
    {
        cout << endl
             << "You have not voted yet. To see your response, vote first." << endl;
    }
}
void updateResponse()
{
    string name, newName, newCnic;
    int place;
    cin.ignore(356, '\n');
    cout << "Enter your name to update your profile: ";
    getline(cin, name);
    for (int i = 0; i < voters_count; i++)
    {
        if (name == voters[i])
        {
            place = i;
        }
    }
    cout << "Enter updated Name: ";
    getline(cin, newName);
    cout << "Enter updated CNIC: ";
    getline(cin, newCnic);
    voters[place] = newName;
    cnics[place] = newCnic;
    cout << endl
         << "YOUR PROFILE IS UPDATED SUCCESSFULLY." << endl;
}
void voter_feedbacks()
{
    string name, feedback;
    int place;
    bool flag = false;
    cin.ignore(356, '\n');
    cout << "Enter your name : ";
    getline(cin, name);
    for (int index = 0; index < voters_count; index++)
    {
        if (name == voters[index])
        {
            flag = true;
            place = index;
            break;
        }
    }
    if (flag == true)
    {
        cout << endl
             << "                Your feedback should be a line long only. " << endl
             << endl;
        cout << "Enter your feedback here: ";
        getline(cin, feedbacks[place]);
        updatedVotersFile();
    }
    else
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << endl
             << "User name not found. Kindly check did you spell your name correct? " << endl;
        cout << "In order to give your feedback, you have to vote first...";
    }
}
void vote_status()
{
    string cnic;
    bool flag = false;
    cin.ignore(356, '\n');
    cout << "Enter your CNIC: ";
    getline(cin, cnic);
    for (int idx = 0; idx < voters_count; idx++)
    {
        if (cnic == cnics[idx])
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        cout << "You have voted successfully!!" << endl;
    }
    else
    {
        cout << "You have not voted yet!!" << endl;
    }
}
void votersDetails()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\tVoters Names \t\t CNIC_Numbers\t\t\t      VOTES " << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 0; i < voters_count; i++)
    {
        cout << setw(15) << voters[i] << setw(30) << cnics[i] << setw(30) << votes[i] << endl;
    }
}
void updatedVotersFile()
{

    fstream file;
    file.open("VotersDetails.txt", ios::out);
    for (int idx = 0; idx < voters_count; idx++)
    {
        file << voters[idx] << ",";
        file << cnics[idx] << ",";
        file << votes[idx] << ",";
        file << feedbacks[idx] << endl;
    }
    file.close();
}
void search_response()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string name;
    int place;
    bool flag = false;
    cin.ignore(356, '\n');
    cout << "Enter the name of the voter to see their response: ";
    getline(cin, name);
    for (int i = 0; i < voters_count; i++)
    {
        if (name == voters[i])
        {
            flag = true;
            place = i;
        }
    }
    if (flag == true)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "You entered name " << name << endl;
        cout << name << "  cnic number is " << cnics[place] << endl;
        cout << name << " voted for " << votes[place] << endl;
    }
    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "No voter found " << endl;
    }
}
void declare_result()
{
    int largest = parties_counter[0];
    bool flagLargest;
    int place = 0;
    for (int index = 0; index < voters_count; index++)
    {
        if (parties_counter[index] > largest)
        {
            largest = parties_counter[index];
            place = index;
            flagLargest = true;
        }
        else if (largest == parties_counter[index])
        {
            flagLargest = false;
        }
    }

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "!************************** ELECTION RESULTS DECLARATION **********************!" << endl
         << endl;
    if (flagLargest == true)
    {
        cout << "\t\t\tThe winner team is " << parties[place] << endl
             << endl;
        cout << "The party " << parties[place] << " with " << largest << " votes, has defeated all other parties." << endl
             << endl;
    }
    else
    {
        cout << "\t\tNo winner team to be declared! There is a tie between two parties... " << endl;
    }
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int idx = 0; idx < adminCount; idx++)
    {
        cout << "The party " << parties[idx] << " has got " << parties_counter[idx] << " votes" << endl;
    }
}
bool validCnic(string cnic)
{
    int size = cnic.length();

    int count = 0;
    bool flag;
    bool check = false;
    if (size == 15)
    { 
    for (int idx = 0; idx < size; idx++)
    {
        if ((cnic[idx] >= 48 && cnic[idx] <= 57) || (cnic[idx] == 45))
        {
            if (cnic[idx] == 45)
            {
                count++;
            }
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (count == 2 && flag == true)
    {
        check = true;
    }
    }
        return check;
}
void viewfeedback()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int index = 0; index < voters_count; index++)
    {
        if (feedbacks[index] == "")
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << voters[index] << "\t has feedbacked nothing yet... " << endl;
        }
        else
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << voters[index] << "\t has feedbacked that ";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << feedbacks[index] << endl;
        }
    }
}
