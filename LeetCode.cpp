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
        auto& matrix = m_sumMatrix;
        int result{ 0 };
        vector<future<int>> vFutures;;

        for (size_t row = row1; row <= row2; ++row) {
            auto a = async(std::launch::async, [&matrix, row, col1, col2]() {
                return accumulate(matrix[row].begin() + col1, matrix[row].begin() + col2 + 1, 0);
            });

            vFutures.push_back(std::move(a));

            //result = accumulate(m_matrix[row].begin() + col1, m_matrix[row].begin() + col2 + 1, result);
        }

        for (auto& fut : vFutures) {
            result += fut.get();
        }
        
        return result;
    }

private:
    void fillSumMatrix(const vector<vector<int>>& matrix) {
        m_sumMatrix = matrix;

        partial_sum(m_sumMatrix[0].begin(), m_sumMatrix[0].end(), m_sumMatrix[0].begin());

        for (size_t row = 1; row < m_sumMatrix.size(); ++row) {
            auto upperRowIter = m_sumMatrix[row - 1].begin();
            auto rowIter = m_sumMatrix[row].begin();
            
            *rowIter += *upperRowIter++;
            
            for_each(m_sumMatrix[row].begin()+1, m_sumMatrix[row].end(), [&rowIter, &upperRowIter](int& val) {
                val += *rowIter++ + *upperRowIter++;
            });
        } 
    }

public:
    vector<vector<int>> m_sumMatrix;
};

int main() {
    vector<vector<int>> sampleVec{ {3, 0, 1, 4, 2},
                                    {5, 6, 3, 2, 1},
                                    {1, 2, 0, 1, 5},
                                    {4, 1, 0, 1, 7},
                                    {1, 0, 3, 0, 5} };

    NumMatrix numMatrix(sampleVec);

    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; // return 8 (i.e sum of the red rectangle)
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl; // return 12 (i.e sum of the blue rectangle)
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; // return 11 (i.e sum of the green rectangle)

    return 0;
}
