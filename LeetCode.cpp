// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> operands;
        unordered_map<string, function<int(int, int)>> operators{
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()}
        };

        for (string& token : tokens) {
            const auto& op = operators.find(token);

            if (op != operators.end()) {
                int b = operands.back();
                operands.pop_back();
                operands.back() = op->second(operands.back(), b);
            } else {
                operands.push_back(stoi(token));
            }
        }

        return operands.front();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
