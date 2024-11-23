// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// https://medium.com/@satyem77/task-scheduler-leetcode-39d579f3440
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for (char t : tasks) { ++freq[t - 'A']; }

        make_heap(freq.begin(), freq.end());
        int maxf = freq.front();
        int f = 0;

        while (!freq.empty() && freq.front() == maxf) {
            pop_heap(freq.begin(), freq.end());
            freq.pop_back();
            ++f;
        }

        return max<size_t>((n + 1) * (maxf - 1) + f, tasks.size());
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}