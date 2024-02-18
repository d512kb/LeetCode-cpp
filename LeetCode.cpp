// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int a = 0, b = height.size() - 1;
        int maxArea = (b - a) * min(height[a], height[b]);

        while (a < b) {
            if (height[a] < height[b]) {
                ++a;
            } else {
                --b;
            }

            maxArea = max(maxArea, (b - a) * min(height[a], height[b]));
        }

        return maxArea;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
