// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;

        for (int i = 1; i < height.size(); ++i) {
            if (height[i - 1] > threshold) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}