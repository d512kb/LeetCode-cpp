// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int a = 0;
        int len = citations.size();
        int b = len;
        int hIndex = 0;

        while (a < b) {
            int mid = (a + b) / 2;
            int cit = len - mid;

            if (citations[mid] < cit) {
                a = mid + 1;
            } else {
                hIndex = cit;
                b = mid;
            }
        }

        return hIndex;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}