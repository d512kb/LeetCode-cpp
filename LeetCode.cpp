// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        const int sz = tiles.size();
        int tilesCovered = 0;
        int result = 0;

        for (int left = 0, right = 0; right < sz && result < carpetLen; ) {
            int rightEdge = tiles[left][0] + carpetLen - 1;

            if (rightEdge >= tiles[right][1]) {
                tilesCovered += tiles[right][1] - tiles[right][0] + 1;
                result = max(result, tilesCovered);
                ++right;
            } else {
                int lastPiece = max(0, rightEdge - tiles[right][0] + 1);
                result = max(result, tilesCovered + lastPiece);
                tilesCovered -= tiles[left][1] - tiles[left][0] + 1;
                ++left;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}