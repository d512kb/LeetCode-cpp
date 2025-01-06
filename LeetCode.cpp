// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        for (int i = 0; i < number.size() - 1; ++i) {
            if (number[i] == digit && number[i] < number[i + 1]) {
                return number.erase(i, 1);
            }
        }

        return number.erase(number.find_last_of(digit), 1);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}