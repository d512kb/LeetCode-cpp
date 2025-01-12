// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr(nums.size());

        transform(nums.begin(), nums.end(), numsStr.begin(), [](int num) { return to_string(num); });
        sort(numsStr.begin(), numsStr.end(), [](const string& a, const string& b) { return a + b > b + a; });

        if (numsStr.front() == "0") { return "0"; }
        return accumulate(numsStr.begin(), numsStr.end(), string());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}