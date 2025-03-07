// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image, sr, sc, image[sr][sc], color);

        return image;
    }
private:
    void fill(vector<vector<int>>& image, int row, int col, int sourceColor, int color) {
        if (row < 0 || row == image.size() || col < 0 || col == image.front().size()) { return; }
        if (image[row][col] != sourceColor || image[row][col] == color) { return; }

        image[row][col] = color;

        fill(image, row, col + 1, sourceColor, color);
        fill(image, row + 1, col, sourceColor, color);
        fill(image, row, col - 1, sourceColor, color);
        fill(image, row - 1, col, sourceColor, color);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}