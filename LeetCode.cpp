// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int negCount = 0;

        for (int n : nums) {
            if (n > 0) {
                seen.push_back(n);
                negCount = 0;
            }
            else {
                if (negCount < seen.size()) {
                    ans.push_back(*(seen.rbegin() + negCount));
                }
                else {
                    ans.push_back(-1);
                }
                ++negCount;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}