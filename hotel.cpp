#include <iostream> // Input / Output
#include <fstream> // File Input / Output
#include <stdio.h> // Password Input
#include <conio.h> // Password getch function
#include <string> // Using string
#include <windows.h> // Using system commands
#include <functional> // Using hash function
#include <io.h> // Making folders via mkdir()
#include <limits> // Using 
#include "./Classes/User.h" // User class
#include "./Classes/Admin.h" // Admin class => Extends User

using namespace std;

// Fucntions decolarations
int showMenu(int);
int getChoise(int, int);
void adminMenu();
void standard();
void createFolders();
bool checkPass();

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
Admin admin("Farhad", "Uneci", "0000000000", "19/03/79", true);

int main() {
    // Centralizing Console
    MoveWindow(hWnd, NewWidth, NewHeight, WindowWidth, WindowHeight, TRUE);
    
    if (!checkPass()) {
        cout << "PASSWORD IS WRONG, TRY AGAIN, APP WILL CLOSE..." << endl;
        system("pause");
        exit(10);
    }

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

bool checkPass() {
    #define ENTER 13
    #define TAB 9
    #define BKSP 8

    char pwd[100];

	int i = 0;
	char ch;

	printf("Enter your password. Hit ENTER to confirm: ");

	while(true){
		ch = getch();	//get key

		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BKSP){
			if(i > 0){
				i--;
				printf("\b \b");		//for backspace
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");				//to replace password character with *
		}
	}

    hash<string> str_hash;
    string input = string(pwd); string adminPass;
    ifstream passFile("pass.pwd"); getline (passFile, adminPass); passFile.close();
    string inputHash = to_string((unsigned int)str_hash(input));
    if(inputHash == adminPass) return true;
	
    return false;
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
            cout << char(221) << "\t" << "6. Change Password" << "\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << "\t" << "0. Exit" << "\t\t\t\t\t\t\t\t\t" << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << char(221) << string(77, ' ') << char(222) << endl;
            cout << string(79, char(254)) << endl;
            return getChoise(0, 6);
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
    int choise;
    while(true) {
        choise = showMenu(1);
        if (choise == 0 ) break;
        switch (choise) {
        case 1:
            admin.addUser();
            break;
        case 3:
            admin.deleteUser(0, ""); // WE NEED TWO
            break;
        case 4: 
            admin.groupDelete();
            break;
        }
    }
}

void standard() {
    cout << "NOT AVAILABLE YET";
    system("pause");
}

void createFolders() {
    mkdir("Users");
}