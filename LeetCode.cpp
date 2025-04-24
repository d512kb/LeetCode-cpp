// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        auto aIndexes = findIndexes(s, a);
        auto bIndexes = findIndexes(s, b);

        vector<int> result;
        int bi = 0;

        for (int aIndex : aIndexes) {
            while (bi < bIndexes.size() && (aIndex - bIndexes[bi]) > k) {
                ++bi;
            }

            if (bi == bIndexes.size()) { return result; }

            if (abs(aIndex - bIndexes[bi]) <= k) {
                result.push_back(aIndex);
            }
        }

        return result;
    }
private:
    vector<int> findIndexes(const string& where, const string& what) {
        string s = what + '#' + where;
        const int sz = s.size();
        const int whatSz = what.size();
        vector<int> z(sz);
        vector<int> result;

        int l = 0;
        int r = 0;

        for (int i = 1; i < sz; ++i) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }

            while (i + z[i] < sz && s[i + z[i]] == s[z[i]]) {
                ++z[i];
            }

            if (z[i] == whatSz) {
                result.push_back(i - whatSz - 1);
            }

            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}