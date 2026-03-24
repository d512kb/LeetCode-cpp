// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const size_t sz = words.size();
        int rightPos = startIndex;
        int leftPos = startIndex;

        do {
            if (words[rightPos] == target) { break; }
            rightPos = (rightPos + 1) % sz;
        } while (rightPos != startIndex);

        do {
            if (words[leftPos] == target) { break; }
            leftPos = (leftPos - 1 + sz) % sz;
        } while (leftPos != startIndex);

        if (leftPos == startIndex && words[leftPos] != target) { return -1; }

        return min((startIndex - leftPos + sz) % sz, (rightPos - startIndex + sz) % sz);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}