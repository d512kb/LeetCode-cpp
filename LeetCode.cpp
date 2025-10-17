// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result;

        for (char c : address) {
            if (c == '.') {
                result += "[.]";
            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}