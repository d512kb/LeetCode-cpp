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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
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
                    m_qCells.push_back(currentCell);
                    result.push_back(getField(n));
                    m_qCells.pop_back();

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
                abs(cell.first - qCell.first) - abs(cell.second - qCell.second) == 0) {
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

    vector<string> getField(int fieldSize) {
        vector<string> result;
        result.reserve(fieldSize);

        for (const auto& qCell : m_qCells) {
            result.push_back(string(fieldSize, '.'));
            result.back().replace(qCell.second, 1, "Q");
        }

        return result;
    }

private:
    bool m_searchFinished = false;
    vector<Cell> m_qCells;

};

int main() {

    Solution sol;

    auto result = sol.solveNQueens(9);

    for (auto v : result) {
        for (auto s : v) {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}
