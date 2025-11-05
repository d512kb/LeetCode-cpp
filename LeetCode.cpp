// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string substring = word;

        while (sequence.find(substring) != string::npos) {
            ++ans;
            substring += word;
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