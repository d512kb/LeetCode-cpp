// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> evens;

        for (int n : nums) {
            if (n % 2 == 0) {
                ++evens[n];
            }
        }

        int maxElem = -1;
        int count = 0;

        for (const auto& even : evens) {
            if (even.second > count) {
                maxElem = even.first;
                count = even.second;
            }
            else if (even.second == count && even.first < maxElem) {
                maxElem = even.first;
            }
        }

        return maxElem;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}