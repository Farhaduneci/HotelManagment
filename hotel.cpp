#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <dir.h>
#include <limits>
#include "./Classes/User.cpp"
#include "./Classes/Admin.cpp"

using namespace std;

int showMenu(int);
int getChoise(int, int);
void adminMenu();
void standard();
void createFolders();

/***********************- POSITIONNING THE CONSOLE WINDOW -*******************************/
//Finding the user's screen resolution
int Width = GetSystemMetrics(SM_CXSCREEN);
int Height = GetSystemMetrics(SM_CYSCREEN);
//Assigning variables for MoveWindows parameters
int WindowWidth = 600;		//--- Used as a parameter to specify the width of the console window (MoveWindows int nWidth)
int WindowHeight = 300;		//--- Used as a parameter to specify the height of the console window (MoveWindows int nHeight)
int NewWidth = (Width - WindowWidth) / 2;		//--- Used as a parameter to center the console window horizontally (MoveWindows int x)
int NewHeight = ((Height - WindowHeight) / 2);		//--- Used as a parameter to center the console window vertically (MoveWindows int y)
//Getting the console window handle
HWND hWnd = GetConsoleWindow();
//Declaring the function
BOOL WINAPI MoveWindow(HWND hWnd, int NewWidth, int NewHeight, int WindowWidth, int WindowHeight, BOOL bRepaint);
/***********************- POSITIONNING THE CONSOLE WINDOW -*******************************/


 // Create a Default Admin
    Admin admin("Farhad", "Uneci", "3861167190", "19/03/79", true);

int main() {
    // Centralizing Console
    MoveWindow(hWnd, NewWidth, NewHeight, WindowWidth, WindowHeight, TRUE);

    // Create Folders
    createFolders();

    // Save Admin Info
    admin.saveToFile();
    
    int choise;
    while(true) {
        choise = showMenu(0);
        if (choise == 0 ) break;
        switch (choise) {
        case 1:
            adminMenu();
            break;
        case 2:
            standard();
            break;
        }
    }
}

int showMenu(int option) {
    switch (option) {
        case 1: { // Admin Panel Menu
            system("CLS");
            cout << string(79, char(254)) << endl;
            cout << char(221) << "\t\t" << "    Hotel Management Project Admin Panel   " << "\t\t\t" << char(222) << endl;
            cout << string(79, char(254)) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << "\t" << "1. Add New User" << "\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "2. Edit User" << "\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "3. Delete User" << "\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "4. Delete Users (More than one)" << "\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "5. View Users" << "\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "6. Change Password" << "\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << "\t" << "0. Exit" << "\t\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << string(79, char(254)) << endl;
            return getChoise(0, 2);
        }
        break;
    
        default: { // Default Menu
            system("CLS");
            cout << string(79, char(254)) << endl;
            cout << char(221) << "\t\t\t" << "    Hotel Management Project    " << "\t\t\t" << char(222) << endl;
            cout << string(79, char(254)) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << "\t" << "1. Administrator Panel" << "\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << "\t" << "2. Hotel Management Panel" << "\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << "\t" << "0. Exit" << "\t\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << string(79, char(254)) << endl;
            return getChoise(0, 2);
        }
        break;
    }
}

int getChoise(int min, int max) {
    int choise = 0;
    askAgain:
    cout << "Enter Your choise: "; cin >> choise;
    if (choise < min || choise > max) {
        cout << "Enter a valid number, ";
        system("pause");
        goto askAgain; 
    }
    return choise;
}

void adminMenu() {
    admin.addUser(
        User("Sina", "Uneci", "", "", false)
    );
    //showMenu(1);
}

void standard() {
    cout << "NOT AVAILABLE YET";
    system("pause");
}


void createFolders() {
    mkdir("Users");
    mkdir("Users/Standard");
    mkdir("Users/Admin");
}