// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const int sz = data.size();
        int bytesToCheck = 0;

        for (int i = 0; i < sz; ++i) {
            if (bytesToCheck > 0) {
                if (!checkFollowingByte(data[i])) { return false; }
                --bytesToCheck;
                continue;
            }

            bytesToCheck = calcBytesToCheck(data[i]);
            if (bytesToCheck < 0) { return false; }
        }

        return bytesToCheck == 0;
    }
private:
    int calcBytesToCheck(int val) const {
        if (val >> 3 == 0b11110) { return 3; }
        if (val >> 4 == 0b1110) { return 2; }
        if (val >> 5 == 0b110) { return 1; }
        if (val >> 7 == 0b0) { return 0; }
        return -1;
    }

    inline bool checkFollowingByte(int val) const {
        return val >> 6 == 0b10;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}