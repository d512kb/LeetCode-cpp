// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chars(128);
        int mLen = magazine.size();
        int i = 0;

        for (const char& c : ransomNote) {
            while (chars[c] == 0 && i < mLen) {
                ++chars[magazine[i++]];
            }

            if (--chars[c] < 0)
                return false;
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
