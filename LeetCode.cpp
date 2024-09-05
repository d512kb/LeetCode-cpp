// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sz = s.size();
        int segments[26];
        memset(&segments, 0, sizeof(segments));

        for (int i = 0; i < sz; ++i) {
            segments[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;

        for (int i = 0; i < sz; ++i) {
            end = max(end, segments[s[i] - 'a']);

            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}