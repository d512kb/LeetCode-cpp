// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        const int maxSize = rows * cols;
        char dirs[]{ 0, 1, 0, -1, 0 };
        char dir = 0; // east
        vector<int> pos{ rStart, cStart };
        vector<vector<int>> result{ {rStart, cStart} };
        int sideSize = 0;

        while (result.size() < maxSize) {
            if (dir == 0 || dir == 2) { ++sideSize; }

            for (int i = 0; i < sideSize; ++i) {
                pos[0] += dirs[dir];
                pos[1] += dirs[dir + 1];

                if (pos[0] < 0 || pos[0] >= rows || pos[1] < 0 || pos[1] >= cols) { continue; }
                result.push_back(pos);
            }

            dir = (dir + 1) % 4;
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