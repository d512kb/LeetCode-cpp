// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) { return {}; }

        sort(changed.begin(), changed.end());
        unordered_map<int, int> nums;

        for (int n : changed) { ++nums[n]; }

        vector<int> result;
        result.reserve(changed.size() / 2);

        for (int n : changed) {
            if (--nums[n] < 0) { continue; }
            if (--nums[n * 2] < 0) { return {}; }
            result.push_back(n);
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