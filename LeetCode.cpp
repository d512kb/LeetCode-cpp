// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        const auto sz = matrix.size();

        for (int row = 0; row < sz; ++row) {
            vector<char> counter(sz + 1);

            for (int col = 0; col < sz; ++col) {
                if (++counter[matrix[row][col]] > 1) { return false; }
            }
        }

        for (int col = 0; col < sz; ++col) {
            vector<char> counter(sz + 1);

            for (int row = 0; row < sz; ++row) {
                if (++counter[matrix[row][col]] > 1) { return false; }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}