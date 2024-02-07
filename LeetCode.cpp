// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;

        int maxDistribution = money / 8;
        int restMoney = money - maxDistribution * 8;

        while (restMoney < (children - maxDistribution) || maxDistribution > children) {
            --maxDistribution;
            restMoney += 8;
        }

        while (maxDistribution >= 0) {
            int restChildren = children - maxDistribution;

            if ((restChildren == 1 && restMoney == 4) || (restChildren == 0 && restMoney > 0)) {
                --maxDistribution;
                restMoney += 8;
            } else {
                break;
            }
        }

        return maxDistribution;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
