// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto seqEdge = is_sorted_until(rbegin(nums), rend(nums));
        if (seqEdge != rend(nums)) {
            iter_swap(seqEdge, upper_bound(rbegin(nums), seqEdge, *seqEdge));
        }

        reverse(seqEdge.base(), end(nums));
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}