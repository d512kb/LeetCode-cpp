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
        int a = 0;
        int b = numbers.size() - 1;
        int sum = 0;

        while (a < b) {
            sum = numbers[a] + numbers[b];
            
            if (sum < target) {
                ++a;
            } else if (sum > target) {
                --b;
            } else {
                break;
            }
        }

        return { a + 1, b + 1 };
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
