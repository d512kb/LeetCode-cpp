// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        vector<char> peaks;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i - 1] == nums[i] || nums[i] == nums[i + 1]) { return false; }

            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                peaks.push_back('^');
            }
            else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
                peaks.push_back('v');
            }

            if (peaks.size() > 2) { return false; }
        }

        return peaks.size() == 2 && peaks[0] == '^' && peaks[1] == 'v';
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}