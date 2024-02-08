// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        if (k == 0)
            return;

        int buf1 = nums[0];
        int buf2;

        int startIndex = 0;
        int newIndex = startIndex;

        for (int i = 0; i < nums.size(); ++i) {
            newIndex = (newIndex + k) % nums.size();

            if (newIndex == startIndex) {
                nums[startIndex] = buf1;
                buf1 = nums[++startIndex];

                newIndex = startIndex;

                continue;
            }

            buf2 = nums[newIndex];
            nums[newIndex] = buf1;
            buf1 = buf2;
        }
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
