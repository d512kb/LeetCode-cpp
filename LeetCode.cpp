// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        if (pq.top() == 0) { return 0; }

        int ans = 0;

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            ++ans;
            --a;
            --b;

            if (a > 0) { pq.push(a); }
            if (b > 0) { pq.push(b); }
        }

        if (!pq.empty()) { ans += pq.top(); }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}