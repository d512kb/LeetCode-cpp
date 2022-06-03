// LeetCode.cpp : Defines the entry point for the application.
//

#include <thread>
#include <future>

#include "LeetCode.h"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        fillSumMatrix(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        auto topLeftAreaSum = m_sumMatrix[row2][col2];
        auto leftAreaSum = col1 != 0 ? m_sumMatrix[row2][col1-1] : 0;
        auto topAreaSum = row1 != 0 ? m_sumMatrix[row1-1][col2] : 0;

        // subtract overlapping area if our region doesn't touch left and top walls
        leftAreaSum -= (row1 > 0 && col1 > 0) ? m_sumMatrix[row1-1][col1-1] : 0;

        return topLeftAreaSum - leftAreaSum - topAreaSum;
    }

private:
    void fillSumMatrix(const vector<vector<int>>& matrix) {
        m_sumMatrix = matrix;

        // manually calculate sums for the first row
        partial_sum(m_sumMatrix[0].begin(), m_sumMatrix[0].end(), m_sumMatrix[0].begin());

        // fill the rest
        for (size_t row = 1; row < m_sumMatrix.size(); ++row) {
            auto upperRowIter = m_sumMatrix[row - 1].begin();
            auto upperRowPrevIter = upperRowIter; // used for excluding diagonal cell's sum
            auto rowIter = m_sumMatrix[row].begin();
            
            *rowIter += *upperRowIter++; // first cell in a row filled by hand
            
            for_each(m_sumMatrix[row].begin()+1, m_sumMatrix[row].end(), [&rowIter,
                                                                          &upperRowIter,
                                                                          &upperRowPrevIter](int& val) {
                // current cell + left + upper - diagonal
                val += *rowIter++ + *upperRowIter++ - *upperRowPrevIter++;
            });
        } 
    }

public:
    vector<vector<int>> m_sumMatrix;
};

int main() {
    vector<vector<int>> sampleVec{  {3, 0, 1, 4, 2},
                                    {5, 6, 3, 2, 1},
                                    {1, 2, 0, 1, 5},
                                    {4, 1, 0, 1, 7},
                                    {1, 0, 3, 0, 5} };

    vector<vector<int>> sampleVec2{ {-4, -5} };
    vector<vector<int>> sampleVec3{ {7, 7, 0},
                                    {-4, -7, 7},
                                    {-4, 0, -2},
                                    {-8, -5, 6 }};

    NumMatrix numMatrix(sampleVec3);

    for (auto vec : numMatrix.m_sumMatrix) {
        for (auto val : vec) {
            cout << val << "\t";
        }
        cout << endl;
    }

    //cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; // return 8 (i.e sum of the red rectangle)
    //cout << numMatrix.sumRegion(1, 2, 2, 4) << endl; // return 12 (i.e sum of the blue rectangle)
    //cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; // return 11 (i.e sum of the green rectangle)

    //cout << numMatrix.sumRegion(0, 0, 0, 0) << endl; 
    //cout << numMatrix.sumRegion(0, 0, 0, 1) << endl;
    //cout << numMatrix.sumRegion(0, 1, 0, 1) << endl;

    cout << numMatrix.sumRegion(1, 0, 2, 2);
    cout << numMatrix.sumRegion(3, 2, 3, 2);
    cout << numMatrix.sumRegion(2, 1, 2, 2);
    cout << numMatrix.sumRegion(0, 2, 2, 2);
    cout << numMatrix.sumRegion(3, 2, 3, 2);


    return 0;
}
