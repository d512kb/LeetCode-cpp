// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        vector<int> prev(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; ++i) {
            swap(prev, result);

            for (int j = 1; j < i; ++j) {
                result[j] = prev[j - 1] + prev[j];
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