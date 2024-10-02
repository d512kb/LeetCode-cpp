// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<char>> cache(s.size() + 1, vector<char>(p.size() + 1, -1));

        return checkPatterns(cache, s, 0, p, 0);
    }
private:
    bool checkPatterns(vector<vector<char>>& cache, const string& s, int sIndex, const string& p, int pIndex) {
        char& c = cache[sIndex][pIndex];
        if (c != -1) { return c; }

        if (pIndex == p.size() && sIndex == s.size()) { return true; }

        bool hasMatch = sIndex < s.size() && p[pIndex] == '.' || p[pIndex] == s[sIndex];
        if (pIndex < p.size() - 1 && p[pIndex + 1] == '*') {
            return c = checkPatterns(cache, s, sIndex, p, pIndex + 2) || (hasMatch && checkPatterns(cache, s, sIndex + 1, p, pIndex));
        }

        return c = hasMatch && checkPatterns(cache, s, sIndex + 1, p, pIndex + 1);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}