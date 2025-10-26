// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            for (int i = 0, j = row.size() - 1; i < j; ++i, --j) {
                swap(row[i], row[j]);
                row[i] = ++row[i] % 2;
                row[j] = ++row[j] % 2;
            }

            if (row.size() % 2) {
                int mid = row.size() / 2;
                row[mid] = ++row[mid] % 2;
            }
        }

        return image;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}