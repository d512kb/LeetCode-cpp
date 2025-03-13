// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        const int sz = security.size();
        vector<int> leftMono(sz);
        vector<int> rightMono(sz);

        for (int i = 1; i < sz; ++i) {
            if (security[i - 1] >= security[i]) {
                leftMono[i] = 1 + leftMono[i - 1];
            }
        }

        for (int i = sz - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                rightMono[i] = 1 + rightMono[i + 1];
            }
        }

        vector<int> result;

        for (int i = 0; i < sz; ++i) {
            if (leftMono[i] >= time && rightMono[i] >= time) { result.push_back(i); }
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