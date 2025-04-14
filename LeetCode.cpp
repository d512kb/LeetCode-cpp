// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countNumbers(string l, string r, int b) {
        constexpr int modulo = 1e9 + 7;

        l = convertToBase(l, b);
        r = convertToBase(r, b);

        // find next lower increasing number
        for (int i = 1; i < l.size(); ++i) {
            if (l[i - 1] > l[i]) {
                for (i; i < l.size(); ++i) {
                    l[i] = l[i - 1];
                }

                break;
            }
        }

        // find prev upper increasing number
        for (int i = 1; i < r.size(); ++i) {
            if (r[i - 1] > r[i]) { // found point of decreasing, decrease left side of the number
                while (i > 0 && r[i - 1] > r[i]) {
                    --r[--i];
                }

                // fill the right part of the number with max values for the base
                for (++i; i < r.size(); ++i) {
                    r[i] = b - 1 + '0';
                }

                r.erase(r.begin(), r.begin() + r.find_first_not_of('0')); // remove leading zeros

                break;
            }
        }

        if (l.size() > r.size()) { return 0; }

        // pair->first for unrestricted digit, pair->second for restricted
        vector<vector<pair<int, int>>> dpLeft(l.size() + 1, vector<pair<int, int>>(b));
        vector<vector<pair<int, int>>> dpRight(r.size() + 1, vector<pair<int, int>>(b));
        fill(dpLeft[0].begin(), dpLeft[0].end(), make_pair(1, 1));
        fill(dpRight[0].begin(), dpRight[0].end(), make_pair(1, 1));

        for (int n = 1, li = l.size() - 1; n <= l.size(); ++n, --li) {
            int val = 0;

            // fill unrestricted values
            for (int j = b - 1; j >= 0; --j) {
                val = (val + dpLeft[n - 1][j].first) % modulo;
                dpLeft[n][j].first = val;
            }

            // fill restricted values
            val = dpLeft[n - 1][l[li] - '0'].second;
            dpLeft[n][l[li] - '0'].second = val;

            for (int j = l[li] - '0' - 1; j >= 0; --j) {
                val = (val + dpLeft[n - 1][j].first) % modulo;
                dpLeft[n][j].second = val;
            }
        }

        for (int n = 1, ri = r.size() - 1; n <= r.size(); ++n, --ri) {
            int val = 0;

            // fill unrestricted values
            for (int j = b - 1; j >= 0; --j) {
                val = (val + dpRight[n - 1][j].first) % modulo;
                dpRight[n][j].first = val;
            }

            // fill restricted values
            val = dpRight[n - 1][r[ri] - '0'].second;
            dpRight[n][r[ri] - '0'].second = val;

            for (int j = r[ri] - '0' - 1; j >= 0; --j) {
                val = (val + dpRight[n - 1][j].first) % modulo;
                dpRight[n][j].second = val;
            }
        }

        return (dpRight.back()[0].second - dpLeft.back()[0].second + 1 + modulo) % modulo;
    }
private:
    string convertToBase(string num, int base) {
        if (num.empty() || num == "0") { return "0"; }

        string result;

        while (!num.empty()) {
            string quotient;
            int n = 0;

            for (char c : num) {
                n = n * 10 + c - '0';

                if (!quotient.empty() || n >= base) {
                    quotient.push_back((n / base) + '0');
                    n = n % base;
                }
            }

            num = std::move(quotient);
            result.push_back(n + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}