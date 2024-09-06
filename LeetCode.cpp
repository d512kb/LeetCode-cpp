// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int numOffset = 10000;
        int freqSz = numOffset * 2 + 1;
        int freq[20001];
        memset(&freq, 0, sizeof(freq));

        for (int i : nums) {
            ++freq[i + numOffset];
        }

        auto cmp = [&freq](int a, int b) { return freq[a] > freq[b]; };
        vector<int> result(k);
        iota(result.begin(), result.end(), 0);
        make_heap(result.begin(), result.end(), cmp);

        int lowestFreq = freq[result.front()];

        for (int i = k; i < freqSz; ++i) {
            if (freq[i] > lowestFreq) {
                pop_heap(result.begin(), result.end(), cmp);
                result.back() = i;
                push_heap(result.begin(), result.end(), cmp);
                lowestFreq = freq[result.front()];
            }
        }

        transform(result.begin(), result.end(), result.begin(), [numOffset](int a) { return a - numOffset; });
        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}