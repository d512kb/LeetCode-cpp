// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;

        for (int i = 0; i < t.size() && sIndex < s.size(); ++i) {
            if (t[i] == s[sIndex]) {
                ++sIndex;
            }
        }

        return sIndex == s.size();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
