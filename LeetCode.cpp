// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string text = a + a;

        while (text.size() < b.size() * 2) {
            text += text;
        }

        int pos = text.find(b);
        if (pos == string::npos) { return -1; }

        float len = pos + b.size();
        return ceil(len / a.size());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}