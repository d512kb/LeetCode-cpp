// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> stringCount;

        for (const auto& str : arr) {
            ++stringCount[str];
        }

        for (const auto& str : arr) {
            if (stringCount[str] == 1) {
                if (--k == 0) { return str; }
            }
        }

        return "";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}