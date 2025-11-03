// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> maxes;

        for (int n : nums) {
            maxes.insert(n);
            if (maxes.size() > 3) {
                maxes.erase(maxes.begin());
            }
        }

        return maxes.size() >= 3 ? *maxes.begin() : *maxes.rbegin();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}