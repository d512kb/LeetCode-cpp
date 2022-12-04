// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <limits>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        int64_t firstSum = 0;
        int64_t secondSum = accumulate(nums.begin(), nums.end(), int64_t());
        int minAverageDistance = numeric_limits<int>::max();
        int minAverageDistanceIndex = 0;
        
        for (int i = 0; i < nums.size()-1; ++i) {
            firstSum += nums[i];
            secondSum -= nums[i];

            int newMin = abs(static_cast<int>(firstSum / (i + 1)) -
                             static_cast<int>(secondSum / (nums.size() - i - 1)));

            if (newMin < minAverageDistance)
            {
                if (newMin == 0)
                    return i;
                
                minAverageDistance = newMin;
                minAverageDistanceIndex = i;
            }
        }

        firstSum += nums[nums.size()-1];

        if (static_cast<int>(firstSum / nums.size()) < minAverageDistance)
        {
            return nums.size() - 1;
        }

        return minAverageDistanceIndex;
    }
};

int main() {
    Solution sol;

    vector<int> nums = { 2,5,3,9,5,3 };
    vector<int> nums2 = { 0 };
    vector<int> nums3 = { 1,2,3,4,5 };

    INIT_TIME(timer);

    cout << "result 1: " << sol.minimumAverageDifference(nums) << endl;
    cout << "result 2: " << sol.minimumAverageDifference(nums2) << endl;
    cout << "result 2: " << sol.minimumAverageDifference(nums3) << endl;

    PRINT_ELAPSED(timer);

    return 0;
}
