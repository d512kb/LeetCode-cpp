// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> seq{ -1 };

        for (int a : arr) {
            if (a < seq.back()) {
                int mx = seq.back();
                while (seq.back() > a) { seq.pop_back(); }
                seq.push_back(mx);
            } else {
                seq.push_back(a);
            }
        }

        return seq.size() - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}