// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string::size_type a = 0;
        string::size_type b = 0;

        while (a != version1.size() || b != version2.size()) {
            int aEnd = version1.find('.', a);
            int bEnd = version2.find('.', b);

            if (aEnd == string::npos) { aEnd = version1.size(); }
            if (bEnd == string::npos) { bEnd = version2.size(); }

            int aVer(0), bVer(0);
            from_chars(&version1[a], &version1[aEnd], aVer);
            from_chars(&version2[b], &version2[bEnd], bVer);

            if (aVer < bVer) { return -1; }
            if (aVer > bVer) { return 1; }

            a = aEnd;
            b = bEnd;
            if (a < version1.size()) { ++a; }
            if (b < version2.size()) { ++b; }
        }

        return 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}