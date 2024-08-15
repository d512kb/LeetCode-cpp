// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        stack.reserve(asteroids.size());

        for (int a : asteroids) {
            if (a > 0) {
                stack.push_back(a);
                continue;
            }

            int aMass = -a;

            while (!stack.empty() && stack.back() > 0 && stack.back() < aMass) {
                stack.pop_back();
            }

            if (stack.empty()) {
                stack.push_back(a);
            } else {
                if (stack.back() < 0) {
                    stack.push_back(a);
                } else if (stack.back() == aMass) {
                    stack.pop_back();
                }
            }
        }

        return stack;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}