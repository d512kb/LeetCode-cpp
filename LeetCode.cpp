// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector<pair<int, int>> stack;
        int result = 0;

        for (int i = 0; i < sz; ++i) {
            int h = heights[i];
            int newStart = i;

            while (!stack.empty() && stack.back().first >= h) {
                auto& prevH = stack.back();
                result = max(result, prevH.first * (i - prevH.second));
                newStart = prevH.second;
                stack.pop_back();
            }

            stack.emplace_back(h, newStart);
        };

        while (!stack.empty()) {
            auto& prevH = stack.back();
            result = max(result, prevH.first * (sz - prevH.second));
            stack.pop_back();
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}