// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canTransform(string start, string result) {
        if (start.size() != result.size()) { return false; }
        const int sz = start.size();

        for (int i = 0, nextX = 0; i < sz; ++i) {
            if (start[i] == result[i]) { continue; }
            if (start[i] == 'R') {
                if (result[i] == 'L') { return false; }

                for (nextX = max(nextX, i + 1); nextX < sz; ++nextX) {
                    if (start[nextX] == 'L') { return false; }
                    if (start[nextX] == 'X') {
                        swap(start[i], start[nextX]);
                        break;
                    }
                }
            }
        }

        for (int i = sz - 1, nextX = i; i >= 0; --i) {
            if (start[i] == result[i]) { continue; }
            if (start[i] == 'L') {
                if (result[i] == 'R') { return false; }

                for (nextX = min(nextX, i - 1); nextX >= 0; --nextX) {
                    if (start[nextX] == 'R') { return false; }
                    if (start[nextX] == 'X') {
                        swap(start[i], start[nextX]);
                        break;
                    }
                }
            }
        }

        return start == result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}