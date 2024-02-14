// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto firstStr = strs[0];
        long prefixLen = firstStr.size();

        for (int i = 1; i < strs.size(); ++i) {
            auto mis = mismatch(firstStr.begin(), firstStr.begin()+prefixLen, strs[i].begin());
            prefixLen = min(prefixLen, static_cast<long>(distance(firstStr.begin(), mis.first)));
        }

        return firstStr.substr(0, prefixLen);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
