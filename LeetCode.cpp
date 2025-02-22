// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = leftSum;
        int rightSum = 0;

        for (int i = k - 1, j = cardPoints.size() - 1; i >= 0; --i, --j) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[j];

            ans = max(ans, leftSum + rightSum);
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