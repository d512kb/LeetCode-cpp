// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        const int targetSize = target.size();
        unordered_map<int, int> prefixCount, suffixCount;

        for (const auto& str : nums) {
            if (target.starts_with(str)) { ++prefixCount[str.size()]; }
            if (target.ends_with(str)) { ++suffixCount[str.size()]; }
        }

        int ans = 0;
        for (const auto [prefixSize, count] : prefixCount) {
            ans += count * suffixCount[target.size() - prefixSize];
        }

        // if prefix can be suffix we should remove half of the amount
        if (targetSize % 2 == 0 && target.ends_with(target.substr(0, targetSize / 2))) {
            ans -= suffixCount[targetSize / 2];
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