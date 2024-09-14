// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<char> visited(arr.size());

        vector<int> stack;
        stack.push_back(start);

        while (!stack.empty()) {
            start = stack.back();
            stack.pop_back();

            if (arr[start] == 0) { return true; }
            visited[start] = 1;

            int right = start + arr[start];
            int left = start - arr[start];

            if (left >= 0 && !visited[left]) { stack.push_back(left); }
            if (right < arr.size() && !visited[right]) { stack.push_back(right); }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}