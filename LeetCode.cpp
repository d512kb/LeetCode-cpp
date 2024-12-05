// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> finishTimes;
        finishTimes.reserve(position.size());

        for (int i = 0; i < position.size(); ++i) {
            finishTimes.emplace_back(position[i], static_cast<float>(target - position[i]) / speed[i]);
        }

        sort(finishTimes.begin(), finishTimes.end());

        int ans = 1;
        float minTime = finishTimes.rbegin()->second;

        for (auto iter = finishTimes.rbegin(); iter != finishTimes.rend(); ++iter) {
            if (iter->second > minTime) {
                minTime = iter->second;
                ++ans;
            }
        };

        return ans;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}