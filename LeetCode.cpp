// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        const int divSz = *max_element(groups.begin(), groups.end()) + 1;
        vector<int> divisors(divSz, -1);

        for (int i = 0; i < elements.size(); ++i) {
            int elem = elements[i];
            if (elem < divSz && divisors[elem] != -1) { continue; }
            for (int el = elem; el < divSz; el += elem) {
                if (divisors[el] == -1) {
                    divisors[el] = i;
                }
            }
        }

        for (int& gr : groups) {
            gr = divisors[gr];
        }

        return groups;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}