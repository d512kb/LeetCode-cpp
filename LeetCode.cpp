// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) {
        int size = grid.size();
        m_adjacentSums.assign(size * size, 0);
        m_diagonalSums.assign(size * size, 0);

        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                int adjSum = 0;
                int diagSum = 0;
                bool leftColValid = col - 1 >= 0;
                bool rightColValid = col + 1 < size;

                if (row - 1 >= 0) {
                    adjSum += grid[row - 1][col];

                    if (leftColValid) {
                        diagSum += grid[row - 1][col - 1];
                    }

                    if (rightColValid) {
                        diagSum += grid[row - 1][col + 1];
                    }
                }

                if (leftColValid) {
                    adjSum += grid[row][col - 1];
                }

                if (rightColValid) {
                    adjSum += grid[row][col + 1];
                }

                if (row + 1 < size) {
                    adjSum += grid[row + 1][col];

                    if (leftColValid) {
                        diagSum += grid[row + 1][col - 1];
                    }

                    if (rightColValid) {
                        diagSum += grid[row + 1][col + 1];
                    }
                }

                int val = grid[row][col];
                m_adjacentSums[val] = adjSum;
                m_diagonalSums[val] = diagSum;
            }
        }
    }

    int adjacentSum(int value) {
        return m_adjacentSums[value];
    }

    int diagonalSum(int value) {
        return m_diagonalSums[value];
    }
private:
    vector<int> m_adjacentSums;
    vector<int> m_diagonalSums;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}