// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m_cache.assign(s1.size() * 100 + s2.size() + 1, 0);

        return checkStrings(s1, s2, s3, 0, 0, 0);
    }
private:
    bool checkStrings(const string& s1, const string& s2, const string& s3, int index1, int index2, int index3) {
        if (index3 == s3.size())
            return index1 == s1.size() && index2 == s2.size();

        if (m_cache[index1 * 100 + index2])
            return false;

        m_cache[index1 * 100 + index2] = 1;
        bool check = false;

        if (index1 < s1.size() && s1[index1] == s3[index3])
            check = checkStrings(s1, s2, s3, index1 + 1, index2, index3 + 1);

        if (index2 < s2.size() && s2[index2] == s3[index3])
            check = check || checkStrings(s1, s2, s3, index1, index2 + 1, index3 + 1);

        return check;
    }

    vector<char> m_cache;
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    bool b = sol.isInterleave("aa", "ab", "abaa");

    PRINT_ELAPSED(timer);
    return 0;
}
