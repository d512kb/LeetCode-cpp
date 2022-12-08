// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indexes;

        for (int i = 0; i < nums.size(); ++i) {
            auto complement = indexes.find(target - nums[i]);
            if (complement != indexes.end()) {
                return { i, complement->second };
            }
            
            indexes.insert({ nums[i], i });
        }

        return {};
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    vector<int> data{ 3,2,4 };
    sol.twoSum(data, 6);

    PRINT_ELAPSED(timer);

    return 0;
}
