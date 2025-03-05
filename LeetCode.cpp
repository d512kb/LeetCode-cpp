// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int val : arr1) {
            while (val) {
                prefixes.insert(val);
                val /= 10;
            }
        }

        int ans = 0;
        for (int val : arr2) {
            while (val) {
                if (prefixes.contains(val)) {
                    ans = max<int>(ans, countDigits(val));
                    break;
                }
                val /= 10;
            }
        }

        return ans;
    }
private:
    inline int countDigits(int n) const {
        int ans = 0;

        while (n) {
            ++ans;
            n /= 10;
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