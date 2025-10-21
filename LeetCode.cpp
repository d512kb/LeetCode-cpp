// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;

        for (char col = s[0]; col <= s[3]; ++col) {
            for (char row = s[1]; row <= s[4]; ++row) {
                string cell;
                cell.push_back(col);
                cell.push_back(row);
                result.push_back(move(cell));
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