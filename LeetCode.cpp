// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> hashChar(128);
        unordered_map<string, char> hashStr;
        istringstream sstr(s);
        string str;

        for (const char& c : pattern) {
            if (!(sstr >> str)) {
                return false;
            }

            auto iter = hashStr.find(str);

            if (hashChar[c].empty() && iter == hashStr.end()) {
                hashChar[c].assign(str);
                hashStr.emplace(move(str), c);
            } else if (hashChar[c] != str) {
                return false;
            }
        }

        return !(sstr >> str);
    }
};

int main() {
    INIT_TIME(timer);
    Solution sol;
    cout << sol.wordPattern("a", "dog");
    PRINT_ELAPSED(timer);
    return 0;
}
