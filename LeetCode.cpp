// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis(1, obstacles[0]);
        vector<int> result(1, 1);
        result.reserve(obstacles.size());

        for (int i = 1; i < obstacles.size(); ++i) {
            if (obstacles[i] >= lis.back()) {
                lis.push_back(obstacles[i]);
                result.push_back(lis.size());
            } else {
                auto iter = upper_bound(lis.begin(), lis.end(), obstacles[i]);
                *iter = obstacles[i];
                result.push_back(1 + distance(lis.begin(), iter));
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}