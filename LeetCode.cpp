// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mapping;

        for (int i = 0; i < arr.size(); ++i) { mapping[arr[i]] = i; }

        for (const auto& piece : pieces) {
            int pos = mapping[piece.front()];

            if (arr.size() - pos < piece.size()) { return false; }

            if (!equal(piece.begin(), piece.end(), arr.begin() + pos)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}