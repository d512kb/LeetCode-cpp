// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct CellsTaken {
        CellsTaken(int n) : n(n), colsTaken(n, 0), lDiagsTaken(n * 2 - 1, 0), rDiagsTaken(n * 2 - 1, 0) { }

        bool setCellTaken(int row, int col) {
            int lDiagIdx = row + (n - col - 1);
            int rDiagIdx = row + col;

            if (colsTaken[col] || lDiagsTaken[lDiagIdx] || rDiagsTaken[rDiagIdx])
                return false;

            colsTaken[col] = 1;
            lDiagsTaken[lDiagIdx] = 1;
            rDiagsTaken[rDiagIdx] = 1;

            return true;
        }

        void setCellFree(int row, int col) {
            int lDiagIdx = row + (n - col - 1);
            int rDiagIdx = row + col;

            colsTaken[col] = 0;
            lDiagsTaken[lDiagIdx] = 0;
            rDiagsTaken[rDiagIdx] = 0;
        }

        int n;
        vector<int> colsTaken;
        vector<int> lDiagsTaken;
        vector<int> rDiagsTaken;
    };
public:
    int totalNQueens(int n) {
        CellsTaken cellsTaken(n);

        int counter = 0;
        int result = 0;
        calcPos(cellsTaken, 0, n, counter, result);
        return result;
    }
private:
    void calcPos(CellsTaken& cellsTaken, int row, int n, int& counter, int& result) {
        if (counter == n) {
            ++result;
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (cellsTaken.setCellTaken(row, c)) {
                ++counter;
                calcPos(cellsTaken, row + 1, n, counter, result);
                --counter;
                cellsTaken.setCellFree(row, c);
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
