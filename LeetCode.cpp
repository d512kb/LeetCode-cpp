// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int index = nums.size() - 1;

        while (index >= 0) {
            int& a = nums[index];
            int& b = nums[a];

            if (a == b) { --index; } else { swap(a, b); }
        }

        return vector<int>(nums.rbegin(), nums.rbegin() + 2);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}