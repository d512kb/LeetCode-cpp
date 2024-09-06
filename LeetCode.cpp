// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        int sz = nums.size();

        for (int i = 0; i < k; ++i) {
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            window.push_back(i);
        }

        vector<int> result{ nums[window.front()] };

        for (int a = 0, b = k; b < sz; ++a, ++b) {
            if (window.front() == a) {
                window.pop_front();
            }

            while (!window.empty() && nums[window.back()] < nums[b]) {
                window.pop_back();
            }

            window.push_back(b);
            result.push_back(nums[window.front()]);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}