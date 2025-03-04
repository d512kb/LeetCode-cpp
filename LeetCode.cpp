// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    class DSet {
    public:
        DSet(int rows, int cols) : m_rows(rows), m_cols(cols), m_parent(m_rows* m_cols, -1) {

        }

        void join(int row1, int col1, int row2, int col2) {
            int mapped1 = row1 * m_cols + col1;
            int mapped2 = row2 * m_cols + col2;

            int id1 = find(mapped1);
            int id2 = find(mapped2);

            if (id1 == id2) { return; }
            if (m_parent[id1] < m_parent[id2]) {
                m_parent[id1] += m_parent[id2];
                m_parent[id2] = id1;
            } else {
                m_parent[id2] += m_parent[id1];
                m_parent[id1] = id2;
            }
        }

        int getIslandId(int row, int col) {
            return find(row * m_cols + col);
        }
    private:
        int m_rows;
        int m_cols;
        vector<int> m_parent;

        int find(int val) {
            if (m_parent[val] < 0) { return val; }
            return m_parent[val] = find(m_parent[val]);
        }
    };
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int rows = grid1.size();
        const int cols = grid1.front().size();
        DSet dset(rows, cols);
        array<char, 5> dirs{ 1, 0, -1, 0, 1 };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid2[row][col] == 1) {
                    for (int i = 0; i < 4; ++i) {
                        int newRow = row + dirs[i];
                        int newCol = col + dirs[i + 1];

                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid2[newRow][newCol] == 1) {
                            dset.join(row, col, newRow, newCol);
                        }
                    }
                }
            }
        }

        unordered_map<int, int> islandUncoveredArea;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid2[row][col] == 1) {
                    int islandId = dset.getIslandId(row, col);
                    islandUncoveredArea[islandId] += 1 - grid1[row][col];
                }
            }
        }

        int ans = 0;

        for (const auto [islandId, uncoveredArea] : islandUncoveredArea) {
            if (uncoveredArea == 0) { ++ans; }
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