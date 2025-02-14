// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : m_matrix(1 + matrix.size(), vector<int>(1 + matrix[0].size())) {
        const int rows = m_matrix.size();
        const int cols = m_matrix[0].size();

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                m_matrix[row][col] = matrix[row - 1][col - 1] + m_matrix[row - 1][col] + m_matrix[row][col - 1] - m_matrix[row - 1][col - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // our coords are shifted so [original coords - 1] will be just row1, col1 etc
        return m_matrix[1 + row2][1 + col2] - m_matrix[row1][1 + col2] - m_matrix[1 + row2][col1] + m_matrix[row1][col1];
    }
private:
    vector<vector<int>> m_matrix;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}