// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<size_t> indexes(names.size());
        iota(indexes.begin(), indexes.end(), 0);

        sort(indexes.begin(), indexes.end(), [&heights](int i, int j) {
            return heights[i] > heights[j];
            });

        vector<string> result(names.size());
        for (int i = 0; i < names.size(); ++i) {
            result[i] = names[indexes[i]];
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