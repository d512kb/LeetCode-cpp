// LeetCode.cpp : Defines the entry point for the application.
//

#include <thread>
#include <future>

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
        int maxIndex = n - 1;
        auto threads = max(2u, thread::hardware_concurrency()-2);

        auto searchProc = [this, maxIndex](Cell startCell) {
            vector<Cell> qCells;
            Cell currentCell = startCell;
            int result = 0;

            do {
                if (cellIsFree(qCells, currentCell)) {
                    if (currentCell.first != maxIndex) {
                        qCells.push_back(currentCell);

                        currentCell.first++;
                        currentCell.second = 0;
                    } else {
                        ++result;

                        traceBack(qCells, currentCell, maxIndex);
                    }
                } else {
                    if (currentCell.second != maxIndex) {
                        ++currentCell.second;
                    } else {
                        traceBack(qCells, currentCell, maxIndex);
                    }
                }
            } while (!qCells.empty());
            
            return result;
        };

        using VecPair = pair<future<int>, shared_ptr<thread>>;
        vector<VecPair> vec;

        for (size_t i = 0; i < n; i++) {
            packaged_task<int(Cell)> task(searchProc);
            auto fut = task.get_future();
            vec.push_back(make_pair(move(fut), make_shared<thread>(move(task), Cell(0, i))));
        }

        for_each(vec.begin(), vec.end(), [](VecPair& v) { v.second->join(); });

        return accumulate(vec.begin(), vec.end(), 0, [](int a, VecPair& v2) { return a + v2.first.get(); });
    }

private:
    inline bool cellIsFree(const vector<Cell>& qCells, const Cell& cell) {
        for (auto& qCell : qCells) {
            if (cell.first == qCell.first || cell.second == qCell.second ||
                abs(cell.first - qCell.first) == abs(cell.second - qCell.second)) {
                return false;
            }
        }

        return true;
    }
    
    inline bool cellIsFree(const Cell& cell) {
        return cellIsFree(m_qCells, cell);
    }

    inline void traceBack(vector<Cell>& qCells, Cell& currentCell, int maxIndex) {
        while (!qCells.empty()) {
            currentCell = qCells.back();
            qCells.pop_back();

            if (currentCell.second != maxIndex) {
                ++currentCell.second;
                return;
            }
        }
    }

    inline void traceBack(Cell& currentCell, int maxIndex) {
        return traceBack(m_qCells, currentCell, maxIndex);
    }

private:
    vector<Cell> m_qCells;
};

int main() {

    Solution sol;

    cout << sol.totalNQueens(9);

    return 0;
}
