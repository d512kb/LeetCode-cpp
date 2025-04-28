// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (char& c : s) {
            int dist = calcDistance('a', c);

            if (dist <= k) {
                c = 'a';
                k -= dist;
            } else {
                c -= k;
                break;
            }
        }

        return s;
    }
private:
    inline int calcDistance(char a, char b) const { // works only for a <= b
        return min(b - a, a + 26 - b);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}