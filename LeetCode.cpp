// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }

private:
    Node* construct(vector<vector<int>>& grid, int row, int col, int regionSize) {
        int val = grid[row][col];
        Node* node = new Node(val, true);

        for (int i = 0; i < regionSize; ++i) {
            for (int j = 0; j < regionSize; ++j) {
                if (grid[i + row][j + col] != val) {
                    node->isLeaf = false;
                    regionSize /= 2;

                    node->topLeft = construct(grid, row, col, regionSize);
                    node->topRight = construct(grid, row, col + regionSize, regionSize);
                    node->bottomLeft = construct(grid, row + regionSize, col, regionSize);
                    node->bottomRight = construct(grid, row + regionSize, col + regionSize, regionSize);

                    return node;
                }
            }
        }

        return node;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
