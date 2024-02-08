// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int firstIndex = 0;
        bool metAgain = false;
        for (int secondIndex = 1; secondIndex < nums.size(); ++secondIndex) {
            if (nums[firstIndex] == nums[secondIndex]) {
                if (metAgain) {
                    continue;
                } else {
                    nums[++firstIndex] = nums[secondIndex];
                    metAgain = true;
                }
            } else {
                nums[++firstIndex] = nums[secondIndex];
                metAgain = false;
            }
        }

        return firstIndex + 1;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
