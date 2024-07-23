// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201);

        for (int n : nums) {
            ++freq[n + 100];
        }

        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            int freqA = freq[a + 100];
            int freqB = freq[b + 100];

            if (freqA == freqB) {
                return b < a;
            } else {
                return freqA < freqB;
            }
        });

        return nums;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}