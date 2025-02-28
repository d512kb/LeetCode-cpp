// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int previousRowDevices = 0;
        int ans = 0;

        for (const auto& row : bank) {
            int currentRowDevices = count(row.begin(), row.end(), '1');

            if (currentRowDevices > 0) {
                ans += previousRowDevices * currentRowDevices;
                previousRowDevices = currentRowDevices;
            }
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