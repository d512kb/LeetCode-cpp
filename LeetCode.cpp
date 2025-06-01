// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        for (int n : nums) {
            if (target % n != 0) { return false; }
        }

        return distribute(nums, target, target);
    }

private:
    bool distribute(vector<int>& values, int64_t value, int64_t target) {
        if (value == 1) {
            return accumulate(values.begin(), values.end(), 1ll, multiplies<>{}) == target;
        }

        for (auto iter = values.begin(); iter != values.end(); ++iter) {
            if (*iter == 1) { continue; }

            if (value % *iter == 0) {
                auto val = *iter;
                *iter = 1;

                if (distribute(values, value / val, target)) {
                    return true;
                }

                *iter = val;
            }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}