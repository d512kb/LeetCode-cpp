// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(canPlace(red, blue), canPlace(blue, red));
    }
private:
    int canPlace(int first, int second) {
        int rowLen = 0;

        while ((first - rowLen - 1) >= 0) {
            first -= ++rowLen;
            swap(first, second);
        }

        return rowLen;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}