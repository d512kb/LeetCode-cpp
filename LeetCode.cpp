// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> hAreas;
        // it works faster when sorted
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                hAreas.insert(hFences[j] - hFences[i]); // no need to abs if sorted
            }
        }

        const int modulo = 1e9 + 7;
        int maxArea = 0;

        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int vArea = vFences[j] - vFences[i];

                if (hAreas.contains(vArea)) {
                    maxArea = max(maxArea, vArea);
                }
            }
        }

        return maxArea > 0 ? static_cast<int64_t>(maxArea) * maxArea % modulo : -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}