// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) { return false; }

        string specials("!@#$%^&*()-+");
        bitset<4> flags;

        for (int i = 0; i < password.size(); ++i) {
            if (i > 0 && password[i - 1] == password[i]) { return false; }

            if (islower(password[i])) { flags[0] = 1; }
            if (isupper(password[i])) { flags[1] = 1; }
            if (isdigit(password[i])) { flags[2] = 1; }
            if (specials.contains(password[i])) { flags[3] = 1; }
        }

        return flags.all();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}