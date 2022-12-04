// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int row = triangle.size()-2; row >= 0; --row)
        {
            for (int col = 0; col < triangle[row].size(); ++col)
            {
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }

        return triangle[0][0];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangles = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    INIT_TIME(timer);

    cout << "result: " << sol.minimumTotal(triangles) << endl;

    PRINT_ELAPSED(timer);

    return 0;
}
