// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class DetectSquares {
public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        ++grid[point[0]][point[1]];
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto& gridVal : grid[x]) {
            int yVal = gridVal.first;
            if (yVal == y) { continue; }

            int size = abs(yVal - y);
            ans += gridVal.second * (grid[x - size][yVal] * grid[x - size][y] + grid[x + size][yVal] * grid[x + size][y]);
        }

        return ans;
    }

private:
    unordered_map<int, unordered_map<int, int>> grid;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}