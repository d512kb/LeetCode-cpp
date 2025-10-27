// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int n = nums[i];

            while (n) {
                result.push_back(n % 10);
                n /= 10;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}