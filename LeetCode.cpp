// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;
        stack<int> monoStack;

        for (int n : nums2) {
            while (!monoStack.empty() && monoStack.top() < n) {
                mapping[monoStack.top()] = n;
                monoStack.pop();
            }

            mapping[n] = -1;
            monoStack.push(n);
        }

        vector<int> result;

        for (int n : nums1) { result.push_back(mapping[n]); }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}