// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto edge1 = edges[0];
        auto edge2 = edges[1];
        vector<int> result;

        sort(edge1.begin(), edge1.end());
        sort(edge2.begin(), edge2.end());
        set_intersection(edge1.begin(), edge1.end(), edge2.begin(), edge2.end(), back_inserter(result));

        return result.front();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}