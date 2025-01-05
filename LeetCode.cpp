// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // on every step we need to align the min element with the max element
        // let's consider decreasing the single Nth max element instead of increasing N-1 elements
        // so on every step we push items down toward min element, which eventually is a simple sum difference
        return accumulate(nums.begin(), nums.end(), 0) - *min_element(nums.begin(), nums.end()) * nums.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}