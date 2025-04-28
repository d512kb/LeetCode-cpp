// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> numsPatterns(nums.size() - 1);

        for (int i = 0; i < numsPatterns.size(); ++i) {
            int v = nums[i + 1] - nums[i];

            if (v > 0) { numsPatterns[i] = 1; } else if (v < 0) { numsPatterns[i] = -1; }
        }

        return countPatterns(numsPatterns, pattern);
    }

private:
    int countPatterns(const vector<int>& where, const vector<int>& what) const {
        vector<int> s;
        s.reserve(where.size() + what.size() + 1);
        copy(what.begin(), what.end(), back_inserter(s));
        s.push_back(numeric_limits<int>::max());
        copy(where.begin(), where.end(), back_inserter(s));

        const int sz = s.size();
        vector<int> zIndex(sz);

        int l = 0;
        int r = 0;
        int result = 0;

        for (int i = 1; i < sz; ++i) {
            if (i < r) {
                zIndex[i] = min(zIndex[i - l], r - i);
            }

            while (i + zIndex[i] < sz && s[i + zIndex[i]] == s[zIndex[i]]) {
                ++zIndex[i];
            }

            if (i + zIndex[i] > r) {
                l = i;
                r = i + zIndex[i];
            }

            if (zIndex[i] == what.size()) {
                ++result;
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