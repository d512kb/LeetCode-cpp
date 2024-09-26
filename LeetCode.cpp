// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") { return "0"; }

        if (num2.size() > num1.size()) { swap(num1, num2); }
        string result(distance(num1.rbegin(), num1.rend()), '0');
        int resultIndex = 0;

        for (auto secondIter = num2.rbegin(); secondIter != num2.rend(); ++secondIter, ++resultIndex) {
            if (result.size() - resultIndex < num1.size()) { result.push_back('0'); }
            int writeToIndex = resultIndex;
            char carry = 0;

            for (auto firstIter = num1.rbegin(); firstIter != num1.rend(); ++firstIter, ++writeToIndex) {
                int a = *firstIter - '0';
                int b = *secondIter - '0';
                int c = result[writeToIndex] - '0';

                int mul = a * b + c + carry;
                result[writeToIndex] = (mul % 10) + '0';
                carry = mul / 10;
            }

            if (carry) { result.push_back(carry + '0'); }
        }

        return string(result.rbegin(), result.rend());
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}