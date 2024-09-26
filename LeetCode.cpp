// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) { return false; }

        vector<int> freqA(26);
        vector<int> freqB(26);

        for (int i = 0; i < s1.size(); ++i) {
            ++freqA[s1[i] - 'a'];
            ++freqB[s2[i] - 'a'];
        }

        if (freqA == freqB) { return true; }

        for (int left = 0, right = s1.size(); right < s2.size(); ++left, ++right) {
            --freqB[s2[left] - 'a'];
            ++freqB[s2[right] - 'a'];

            if (freqA == freqB) { return true; }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}