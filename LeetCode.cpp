// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums;

        for (int n : arr) {
            if (n % 2 == 0 && nums.contains(n / 2) || nums.contains(n * 2)) { return true; }

            nums.insert(n);
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