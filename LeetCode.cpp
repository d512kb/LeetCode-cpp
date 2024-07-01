// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            int& v = nums[i];
            int index = v > 0 ? v : -v;

            if (nums[index] < 0)
                return index;

            nums[index] = -nums[index];
        }

        return 0;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}