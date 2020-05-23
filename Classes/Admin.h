#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <list>

using namespace std;

class Admin: public User {
    list<string> users;
public:
    Admin(string first, string last, string nCode, string bDay, bool pos):
    User(first, last, nCode, bDay, pos) {
        loadUsers();
    }

    void loadUsers() {
        string userCode;
        ifstream readInfo("./Users/users.info");
        while (getline (readInfo, userCode)) {
            users.push_back(userCode);
        }
        readInfo.close();
    }
    
    bool addUser() {
        string first, last, nCode, bDay;
        stringstream info = askInfo(0);
        info >> first >> last >> nCode >> bDay;
        if (!userExist(nCode)) {
            User user(first, last, nCode, bDay, false); // Standard User
            user.saveToFile();
            users.push_back(nCode);
            saveToUsersFile(nCode);
            return true;
        }
        cout << "User already exists, try again. "; system("pause");
        return false;
    }

    bool deleteUser() {
        string nCode;
        stringstream info = askInfo(1);
        info >> nCode;
        if (!userExist(nCode)) {
            cout << "User does not exist, "; system("pause");
            return false;
        }
        string nCodeCopy = nCode;
        string fileName = nCodeCopy.append(".user");
        char fileNameChar[] = ""; strcpy(fileNameChar, fileName.c_str()); // Make File name a char array
        char path[] = "./Users/"; strcat(path, fileNameChar); // Make the full path
        if( remove( path ) != 0 ) { // Remove the file
            perror( "Error deleting user" ); system("pause");
        } else { puts( "User successfully deleted" ); deleteFromUsersFile(nCode); ("pause"); }
        return true;
    }

    stringstream askInfo(int option) {
        string first, last, nCode, bDay;
        stringstream info;
        switch (option) {
        case 1: // Delete User
            cout << "Enter Natinal Code: "; cin >> nCode; info << nCode;
            break;
        
        default: {
            cout << "Enter First name: "; cin >> first; info << first;
            cout << "Enter Last name: "; cin >> last; info << ' ' << last;
            cout << "Enter Natinal code: "; cin >> nCode; info << ' ' << nCode;
            cout << "Enter Birth day (1/1/90): "; cin >> bDay; info << ' ' << bDay;
        }
        break;
        }
        return info;
    }

    bool userExist(string nCode) {
        for (string userCode: users) {
            if (userCode == nCode)
                return true;
        }
        return false;
    }

    bool saveToUsersFile(string userCode) {
        string fileName = "users.info";
        ofstream fileStream;
        try {
            fileStream.open("./Users/" + fileName, ios::app); // open the file, or create it.
            fileStream << userCode << endl;
            fileStream.close(); // We always need to close our files.
        } catch (const exception& ex) {
            cerr << ex.what() << endl;
            system("pause");
            return false;
        }
        return true;
    }

    void deleteFromUsersFile(string userCode) {
        string line;
        stringstream prevData;
        vector<string> data;
        ifstream readInfo("./Users/users.info");
        while (getline (readInfo, line)) {
            if (line == userCode)
                continue;
            prevData << line << ' ';
        }
        readInfo.close();
        ofstream writeNewData("./Users/users.info");
        while (getline(prevData, line, ' ')) {
            data.push_back(line);
        }
        for (auto newData: data) {
            writeNewData << newData << endl;
        }
        writeNewData.close();
        system("pause");
    }
};