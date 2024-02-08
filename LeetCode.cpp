// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int vote = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (val == nums[i]) {
                ++vote;
            } else {
                --vote;

                if (vote == 0) {
                    vote = 1;
                    val = nums[i];
                }
            }
        }

        return val;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
