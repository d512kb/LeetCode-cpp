// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(begin(stones), end(stones));

        while (stones.size() > 1) {
            pop_heap(begin(stones), end(stones));
            int a = stones.back();
            stones.pop_back();
            pop_heap(begin(stones), end(stones));

            if (a == stones.back()) {
                stones.pop_back();
            } else {
                stones.back() = a - stones.back();
                push_heap(begin(stones), end(stones));
            }
        }

        return stones.empty() ? 0 : stones.front();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}