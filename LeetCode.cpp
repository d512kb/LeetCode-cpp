// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = 0;
        int b = nums.size() - 1;

        while (a <= b) {
            int mid = (a + b) / 2;

            if (nums[mid] < target) {
                a = mid + 1;
            } else if (nums[mid] > target) {
                b = mid - 1;
            } else {
                int ra = a;
                int rb = mid;
                int rmid = 0;

                while (ra <= rb) {
                    rmid = (ra + rb) / 2;

                    if (nums[rmid] == target) {
                        rb = rmid - 1;
                    } else {
                        ra = rmid + 1;
                    }
                }

                a = ra;
                ra = mid;
                rb = b;

                while (ra <= rb) {
                    rmid = (ra + rb) / 2;

                    if (nums[rmid] == target) {
                        ra = rmid + 1;
                    } else {
                        rb = rmid - 1;
                    }
                }

                return { a, rb };
            }
        }

        return { -1, -1 };
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
