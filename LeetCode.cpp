// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return getGcd(str1, str2, 0, 0);
    }
private:
    string getGcd(string& str1, string& str2, int p1, int p2) {
        int p1orig = p1;
        int p2orig = p2;

        for (; p1 < str1.size() && p2 < str2.size(); ++p1, ++p2) {
            if (str1[p1] != str2[p2]) {
                return "";
            }
        }

        if (p1 == str1.size() && p2 == str2.size()) {
            return str1.substr(p1orig);
        }

        if (p1 == str1.size()) {
            p1 = p1orig;
        } else {
            p2 = p2orig;
        }

        return getGcd(str1, str2, p1, p2);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}