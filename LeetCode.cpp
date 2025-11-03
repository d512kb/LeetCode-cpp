// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool heavy = mass >= 100;
        bool bulky = length >= 10'000 || width >= 10'000 || height >= 10'000;

        int64_t vol = length;
        vol *= width;
        vol *= height;

        bulky = bulky || vol >= 1'000'000'000;

        if (bulky && heavy) { return "Both"; }
        if (bulky) { return "Bulky"; }
        if (heavy) { return "Heavy"; }

        return "Neither";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}