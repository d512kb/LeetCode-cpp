// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// free cells for any Q at the coords (x,y)
//y + k, x + k + 1 / x - k - 1 (k = +-1..n)
//y - k, x + k + 1 / x - k - 1
//x + k, y + k + 1 / y - k - 1
//x - k, y + k + 1 / y - k - 1

class Solution {
    using Cell = pair<int, int>;
    using SetCells = set<Cell>;

public:
    int totalNQueens(int n) {
        int result = 0;
        int maxIndex = n - 1;
        Cell currentCell(0, 0);
        
        m_searchFinished = false;
        m_qCells.clear();

        while (!m_searchFinished) {
            if (cellIsFree(currentCell)) {
                if (currentCell.first != maxIndex) {
                    m_qCells.push_back(currentCell);

                    currentCell.first++;
                    currentCell.second = 0;
                } else {
                    ++result;

                    traceBack(currentCell, maxIndex);
                }
            } else {
                if (currentCell.second != maxIndex) {
                    ++currentCell.second;
                } else {
                    traceBack(currentCell, maxIndex);
                }
            }
        }

        return result;
    }

private:
    inline bool cellIsFree(const Cell& cell) {
        for (auto& qCell : m_qCells) {
            if (cell.first == qCell.first || cell.second == qCell.second ||
                abs(cell.first - qCell.first) == abs(cell.second - qCell.second)) {
                return false;
            }
        }

        return true;
    }

    inline void traceBack(Cell& currentCell, int maxIndex) {
        while (!m_qCells.empty()) {
            currentCell = m_qCells.back();
            m_qCells.pop_back();

            if (currentCell.second != maxIndex) {
                ++currentCell.second;
                return;
            }
        }

        m_searchFinished = true;
    }

private:
    bool m_searchFinished = false;
    vector<Cell> m_qCells;
};

int main() {

    Solution sol;

    cout << sol.totalNQueens(9);

    return 0;
}
