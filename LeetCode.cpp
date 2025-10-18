// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string interpret(string command) {
        int index = 0;
        const int sz = command.size();
        string result;

        while (index < sz) {
            if (command[index] == 'G') {
                result.push_back('G');
                ++index;
            }
            else {
                if (command[index + 1] == ')') {
                    result.push_back('o');
                    index += 2;
                }
                else {
                    result += "al";
                    index += 4;
                }
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