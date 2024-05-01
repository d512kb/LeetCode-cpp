// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result(max(a.size(), b.size()), 0);
        int r = result.size() - 1;
        char c = 0;
        int ai = a.size() - 1;
        int bi = b.size() - 1;

        while (ai >= 0 || bi >= 0) {
            char sum = c;
            if (ai >= 0) sum += a[ai--] - '0';
            if (bi >= 0) sum += b[bi--] - '0';
            result[r--] = '0' + (sum & 1);
            c = sum >> 1;
        }

        return c ? "1" + result : result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
