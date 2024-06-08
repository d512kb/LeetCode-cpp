// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (auto iter = triangle.rbegin(), preEndIter = prev(triangle.rend()); iter != preEndIter; ++iter) {
            auto rowIter = iter->begin();
            for (auto& i : *next(iter)) {
                i += min(*rowIter, *next(rowIter));
                ++rowIter;
            }
        }
        return triangle[0][0];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
