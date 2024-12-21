// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int num, int denom) {
        if (num == 0) { return "0"; }

        int64_t numerator = num;
        int64_t denominator = denom;

        string result;
        if (numerator < 0 ^ denominator < 0) { result.push_back('-'); }

        numerator = abs(numerator);
        denominator = abs(denominator);
        result.append(to_string(numerator / denominator));

        int64_t rem = numerator % denominator;
        if (rem == 0) { return result; }

        result.push_back('.');
        unordered_map<int64_t, int> positions;
        rem *= 10;

        while (rem != 0 && !positions.contains(rem)) {
            positions[rem] = result.size();
            result.append(to_string(rem / denominator));
            rem %= denominator;
            rem *= 10;
        }

        if (rem != 0) {
            result.insert(positions[rem], 1, '(');
            result.push_back(')');
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