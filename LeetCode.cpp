// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> rightCandles(s.size(), s.size() - 1);
        vector<int> leftCandles(s.size());
        vector<int> prefixSum(s.size());
        int plates = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '|') {
                for (int j = i; j >= 0 && rightCandles[j] > i; --j) {
                    rightCandles[j] = i;
                }
            } else {
                ++plates;
            }

            prefixSum[i] = plates;
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '|') {
                for (int j = i; j < s.size() && leftCandles[j] < j; ++j) {
                    leftCandles[j] = i;
                }
            }
        }

        vector<int> result;

        for (auto& q : queries) {
            int leftEdge = rightCandles[q[0]];
            int rightEdge = leftCandles[q[1]];

            if (rightEdge > leftEdge) {
                result.push_back(prefixSum[rightEdge] - prefixSum[leftEdge]);
            } else {
                result.push_back(0);
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