// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = numeric_limits<int>::max();
        int b = a;

        for (int n : nums) {
            if (n <= a) {
                a = n;
            } else if (n <= b) {
                b = n;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}