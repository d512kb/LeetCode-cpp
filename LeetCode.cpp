// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string result(s);

        for (int i = 0, sz = s.size(); i < sz; ++i) {
            result[i] = s[(i + k) % sz];
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}