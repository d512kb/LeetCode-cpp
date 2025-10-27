// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int start = 0, end = s.size() - 1; start < end; ++start, --end) {
            swap(s[start], s[end]);
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}