#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    hash<string> hash;
    cout << to_string((unsigned int)hash("123"));
    return 0;
}
