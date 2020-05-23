#include <string>

using namespace std;

class User {
    string first, last, nCode, bDay;
    bool pos;
public:
    static int numberOfUsers;
    User(string first, string last, string nCode, string bDay, bool pos);
    bool saveToFile();
    virtual ~User();
};
