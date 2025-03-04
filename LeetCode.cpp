// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
            numbers.insert(reverseInt(num));
        }

        return numbers.size();
    }
private:
    inline int reverseInt(int val) {
        int result = 0;

        while (val) {
            result = (result * 10) + val % 10;
            val /= 10;
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