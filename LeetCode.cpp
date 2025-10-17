// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);

        for (char c : s) {
            ++freq[c - 'a'];
        }

        int vovelFreq = exchange(freq[0], 0);
        vovelFreq = max(vovelFreq, exchange(freq['e' - 'a'], 0));
        vovelFreq = max(vovelFreq, exchange(freq['i' - 'a'], 0));
        vovelFreq = max(vovelFreq, exchange(freq['o' - 'a'], 0));
        vovelFreq = max(vovelFreq, exchange(freq['u' - 'a'], 0));

        return *max_element(freq.begin(), freq.end()) + vovelFreq;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}