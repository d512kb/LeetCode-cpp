// LeetCode.cpp : Defines the entry point for the application.
//

#include <thread>
#include <future>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        partial_sum(nums.begin(), nums.end(), back_inserter(result));
        return result;
    }
};

int main() {
    return 0;
}
