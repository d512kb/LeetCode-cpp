// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        int i = 0;
        for (; i < k; ++i) {
            result.push_back(move(points[i]));
        }

        auto lmb = [](auto& v1, auto& v2) {
            return sqrt(v1[0] * v1[0] + v1[1] * v1[1]) < sqrt(v2[0] * v2[0] + v2[1] * v2[1]);
        };

        make_heap(begin(result), end(result), lmb);

        for (; i < points.size(); ++i) {
            if (lmb(points[i], result.front())) {
                pop_heap(begin(result), end(result), lmb);
                swap(result.back(), points[i]);
                push_heap(begin(result), end(result), lmb);
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