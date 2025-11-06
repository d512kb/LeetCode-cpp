// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int leftSum = 0;
        int leftIndex = 0;

        for (int i = 0; i < arr.size() - 2; ++i) {
            leftSum += arr[i];
            totalSum -= arr[i];

            if (leftSum * 2 == totalSum) {
                int centerSum = 0;

                for (int j = i + 1; j < arr.size() - 1; ++j) {
                    centerSum += arr[j];

                    if (centerSum == leftSum) { return true; }
                }

                return false;
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