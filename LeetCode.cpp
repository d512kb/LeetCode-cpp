// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        auto number = to_string(num);

        for (char& c : number) {
            if (c == '6') {
                c = '9';
                break;
            }
        }

        return stoi(number);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}