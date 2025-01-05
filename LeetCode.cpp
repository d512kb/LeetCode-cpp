// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();
        const int sz = rows * cols;
        pair<int, int> rightEdge(0, 0);
        pair<int, int> leftEdge(0, 0);
        vector<int> result;
        bool up = true;

        while (result.size() < sz) {
            if (up) {
                for (pair<int, int> cell = leftEdge; cell >= rightEdge; cell.first -= 1, cell.second += 1) {
                    result.push_back(mat[cell.first][cell.second]);
                }
            } else {
                for (pair<int, int> cell = rightEdge; cell <= leftEdge; cell.first += 1, cell.second -= 1) {
                    result.push_back(mat[cell.first][cell.second]);
                }
            }

            rightEdge.second += 1;
            if (rightEdge.second == cols) {
                rightEdge.second -= 1;
                rightEdge.first += 1;
            }
            leftEdge.first += 1;
            if (leftEdge.first == rows) {
                leftEdge.first -= 1;
                leftEdge.second += 1;
            }
            up = !up;
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