// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int sz = chars.size();
        int insPos = 0;
        int readPos = 0;

        while (readPos < sz) {
            char currCh = chars[readPos];
            int startReadPos = readPos++;

            while (readPos < sz && chars[readPos] == currCh) {
                ++readPos;
            }

            int len = readPos - startReadPos;
            chars[insPos++] = currCh;

            if (len > 1) {
                for (char c : to_string(len)) {
                    chars[insPos++] = c;
                }
            }
        }

        return insPos;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}