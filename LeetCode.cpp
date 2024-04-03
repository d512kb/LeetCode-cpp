// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty())
            return result;

        iterate(digits, 0, "", result);

        return result;
    }
private:
    void iterate(const string& rest, int index, string collected, vector<string>& result) {
        if (index == rest.size()) {
            result.push_back(move(collected));
            return;
        }

        int digit = rest[index] - '0';

        for (char c : keys[digit]) {
            iterate(rest, index + 1, collected + c, result);
        }
    }
private:
    vector<string> keys{ "", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
