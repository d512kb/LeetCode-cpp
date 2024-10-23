// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string str;

        for (char targetChar : target) {
            str.push_back('a');

            for (char c = 'a'; c <= 'z'; ++c) {
                str.back() = c;
                result.push_back(str);

                if (c == targetChar) {
                    break;
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}