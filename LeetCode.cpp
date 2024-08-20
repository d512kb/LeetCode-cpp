// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    using Ptr = string(Solution::*)(int);
    Ptr ptrs[9]{ &Solution::gen1, &Solution::gen2, &Solution::gen3,
                  &Solution::gen4, &Solution::gen5, &Solution::gen6,
                  &Solution::gen7, &Solution::gen8, &Solution::gen9 };
public:
    string largestPalindrome(int n, int k) {
        return (this->*ptrs[k - 1])(n);
    }
private:
    string gen1(int n) {
        string result(n, '9');

        return result;
    }

    string gen2(int n) {
        string result(n, '9');

        result.front() = '8';
        result.back() = '8';

        return result;
    }

    string gen3(int n) {
        string result(n, '9');

        return result;
    }

    string gen4(int n) {
        string result(n, '9');

        if (n > 4) {
            result[0] = '8';
            result[1] = '8';
            result[n - 1] = '8';
            result[n - 2] = '8';
        } else {
            return string(n, '8');
        }

        return result;
    }

    string gen5(int n) {
        string result(n, '9');

        result.front() = '5';
        result.back() = '5';

        return result;
    }

    string gen6(int n) {
        if (n == 1) {
            return "6";
        } else if (n == 2) {
            return "66";
        } else if (n == 3) {
            return "888";
        }

        string result(n, '9');
        result.front() = '8';
        result.back() = '8';

        if (n % 2) {
            result[n / 2] = '8';
        } else {
            result[n / 2 - 1] = '7';
            result[n / 2] = '7';
        }

        return result;
    }

    string gen7(int n) {
        static string preGen[]{ "", "7", "77", "959", "9779", "99799", "999999", "9994999",
                                 "99944999", "999969999", "9999449999", "99999499999" };

        if (n < 12) {
            return preGen[n];
        }

        string result(n, '9');

        int s = n / 6;
        if (s % 2) { s -= 1; }
        int fillLen = n - s * 6;

        result.replace(s * 3, fillLen, preGen[fillLen]);

        return result;
    }

    string gen8(int n) {
        string result(n, '9');

        if (n > 6) {
            result[0] = '8';
            result[1] = '8';
            result[2] = '8';
            result[n - 3] = '8';
            result[n - 2] = '8';
            result[n - 1] = '8';
        } else {
            return string(n, '8');
        }

        return result;
    }

    string gen9(int n) {
        string result(n, '9');

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}