// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct Number {
            int counter = 0;
            int firstPos = 0;
            int lastPos = 0;
        };

        int maxDegree = 0;
        unordered_map<int, Number> numbers;

        for (int i = 0; i < nums.size(); ++i) {
            auto& numData = numbers[nums[i]];
            if (numData.counter == 0) { numData.firstPos = i; }
            numData.lastPos = i;

            if (++numData.counter > maxDegree) {
                maxDegree = numData.counter;
            }
        }

        unordered_set<int> maxNumbers;

        for (const auto& [num, numData] : numbers) {
            if (numData.counter == maxDegree) {
                maxNumbers.insert(num);
            }
        }

        int ans = nums.size();

        for (int n : maxNumbers) {
            ans = min(ans, 1 + numbers[n].lastPos - numbers[n].firstPos);
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