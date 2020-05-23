#include <string>

using namespace std;

class Admin: public User {
public:
    Admin(string first, string last, string nCode, string bDay, bool pos):
    User(first, last, nCode, bDay, pos) {}
    
    bool addUser(User user) {
        user.saveToFile();
        return true;
    }

    
};