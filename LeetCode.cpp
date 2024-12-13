// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    vector<string> teens{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    vector<string> decimals{ "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

public:
    string numberToWords(int num) {
        if (num == 0) { return "Zero"; }

        int h = (num / 100) % 10;
        int t = ((num / 10) % 10) * 10 + (num % 10);
        num /= 1000;
        int hK = (num / 100) % 10;
        int tK = ((num / 10) % 10) * 10 + (num % 10);
        num /= 1000;
        int hM = (num / 100) % 10;
        int tM = ((num / 10) % 10) * 10 + (num % 10);
        num /= 1000;
        int tB = num % 10;

        string result;

        if (tB) { result += teens[tB] + " Billion "; }
        if (hM) { result += teens[hM] + " Hundred "; }
        if (tM) { result += convertDecimal(tM) + " "; }
        if (hM + tM) { result += "Million "; }
        if (hK) { result += teens[hK] + " Hundred "; }
        if (tK) { result += convertDecimal(tK) + " "; }
        if (hK + tK) { result += "Thousand "; }
        if (h) { result += teens[h] + " Hundred "; }
        if (t) { result += convertDecimal(t); }

        if (result.back() == ' ') { result.pop_back(); }

        return result;
    }
private:
    string convertDecimal(int num) {
        if (num < 20) { return teens[num]; }
        if (num % 10) { return decimals[num / 10] + " " + teens[num % 10]; }

        return decimals[num / 10];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}