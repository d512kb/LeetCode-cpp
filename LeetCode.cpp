// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) { return {}; }
        int psz = p.size();
        int ssz = s.size();

        int pFreq[26]{ 0 };
        for (char c : p) { ++pFreq[c - 'a']; }

        int sFreq[26]{ 0 };
        for (int i = 0; i < psz - 1; ++i) { ++sFreq[s[i] - 'a']; }

        vector<int> result;
        for (int a = 0, b = psz - 1; b < ssz; ++a, ++b) {
            ++sFreq[s[b] - 'a'];

            if (equal(sFreq, sFreq + 26, pFreq)) {
                result.push_back(a);
            }

            --sFreq[s[a] - 'a'];
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}