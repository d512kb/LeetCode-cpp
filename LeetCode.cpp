// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto b = upper_bound(numbers.begin(), numbers.end(), target);

        if (b == numbers.end())
            b = numbers.end() - 1;
        else if (b == numbers.begin())
            ++b;

        auto a = lower_bound(numbers.begin(), numbers.end(), target - *b);

        while (*a + *b != target) {
            --b;
            a = lower_bound(numbers.begin(), numbers.end(), target - *b);
        }

        int aVal = static_cast<int>(distance(numbers.begin(), a) + 1);
        int bVal = static_cast<int>(distance(numbers.begin(), b) + 1);

        return { min(aVal, bVal), max(aVal, bVal) };
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
