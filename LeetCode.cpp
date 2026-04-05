// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int dur = releaseTimes[0];
        char key = keysPressed[0];

        for (int i = 1; i < releaseTimes.size(); ++i) {
            int diff = releaseTimes[i] - releaseTimes[i - 1];

            if (diff > dur) {
                dur = diff;
                key = keysPressed[i];
            }
            else if (diff == dur && keysPressed[i] > key) {
                key = keysPressed[i];
            }
        }

        return key;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}