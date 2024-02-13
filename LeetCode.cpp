// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        pair<int, int> maxHeight{ 0,0 };
        int localWater = 0;
        int totalWater = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] >= maxHeight.first) {
                totalWater += localWater;
                localWater = 0;
                maxHeight.first = height[i];
                maxHeight.second = i;
            } else {
                localWater += maxHeight.first - height[i];
            }
        }

        maxHeight.first = 0;
        localWater = 0;

        for (int i = height.size() - 1; i > maxHeight.second; --i) {
            if (height[i] >= maxHeight.first) {
                totalWater += localWater;
                localWater = 0;
                maxHeight.first = height[i];
            } else {
                localWater += maxHeight.first - height[i];
            }
        }

        return totalWater + localWater;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
