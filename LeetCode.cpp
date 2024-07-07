// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size();
        int sz2 = text2.size();

        vector<int> dpCurr(sz2 + 1);
        vector<int> dpPrev(sz2 + 1);

        for (int i = 0; i < sz1; ++i) {
            swap(dpCurr, dpPrev);

            for (int j = 0; j < sz2; ++j) {
                if (text1[i] == text2[j]) {
                    dpCurr[j + 1] = 1 + dpPrev[j];
                } else {
                    dpCurr[j + 1] = max(dpCurr[j], dpPrev[j + 1]);
                }
            }
        }

        return dpCurr.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}