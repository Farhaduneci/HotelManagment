#include <string>
#include "User.h"

using namespace std;

class Admin: public User {
public:
    Admin(string first, string last, string nCode, string bDay, bool pos);
    
    bool addUser(User user);

    virtual ~Admin();
};
