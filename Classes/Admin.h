#include <string>
#include <vector>
#include <sstream>
#include <fstream>
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
        stringstream info = askInfo();
        info >> first >> last >> nCode >> bDay;
        if (!userExist(nCode)) {
            User user(first, last, nCode, bDay, false); // Standard User
            user.saveToFile();
            users.push_back(nCode);
            saveToUsersFile(nCode);
            return true;
        }
        cout << "User already exists, try again. ";
        system("pause");
        return false;
    }

    bool deleteUser() {
        
    }

    stringstream askInfo() {
        string first, last, nCode, bDay;
        stringstream info;
        cout << "Enter First name: "; cin >> first; info << first;
        cout << "Enter Last name: "; cin >> last; info << ' ' << last;
        cout << "Enter Natinal code: "; cin >> nCode; info << ' ' << nCode;
        cout << "Enter Birth day (1/1/90): "; cin >> bDay; info << ' ' << bDay;
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
};