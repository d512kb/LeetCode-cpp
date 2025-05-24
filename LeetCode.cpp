// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const auto rows = matrix.size();
        const auto cols = matrix.front().size();
        int ans = 0;

        for (size_t rowA = 0; rowA < rows; ++rowA) {
            vector<int> compressedRows(cols);

            for (size_t rowB = rowA; rowB < rows; ++rowB) {
                unordered_map<int, size_t> sumsCounter{ {0, 1} };
                int totalSum = 0;

                for (size_t col = 0; col < cols; ++col) {
                    compressedRows[col] += matrix[rowB][col];
                    totalSum += compressedRows[col];

                    ans += sumsCounter[totalSum - target];
                    ++sumsCounter[totalSum];
                }
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}