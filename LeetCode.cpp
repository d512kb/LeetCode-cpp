// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;

        for (int i = 0; i < strs.size(); ++i) {
            bool unique = true;
            const auto& str = strs[i];

            for (int j = 0; j < strs.size(); ++j) {
                if (i != j && isSubsequence(str, strs[j])) {
                    unique = false;
                    break;
                }
            }

            if (unique) {
                ans = max<int>(ans, str.size());
            }
        }

        return ans;
    }
private:
    bool isSubsequence(const string& str1, const string& str2) {
        if (str1.size() > str2.size()) { return false; }

        size_t pos = -1;

        for (char c : str1) {
            pos = str2.find(c, pos + 1);
            if (pos == string::npos) { return false; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}