// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const auto sz = boxes.size();
        int rightBalls = 0;
        int rightMoves = 0;

        for (int i = sz - 1; i >= 0; --i) {
            rightMoves += rightBalls;
            if (boxes[i] == '1') { ++rightBalls; }
        }

        int leftMoves = 0;
        int leftBalls = 0;
        vector<int> result(sz);

        for (int i = 0; i < sz; ++i) {
            leftMoves += leftBalls;
            result[i] = leftMoves + rightMoves;

            if (boxes[i] == '1') {
                ++leftBalls;
                --rightBalls;
            }

            rightMoves -= rightBalls;
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