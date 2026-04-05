// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int maxDistance = nums.size() * 3;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int dist = abs(i - j) + abs(i - k) + abs(j - k);

                        if (dist < maxDistance) {
                            maxDistance = dist;
                        }
                    }
                }
            }
        }

        return maxDistance < nums.size() * 3 ? maxDistance : -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}