// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        array<reference_wrapper<string>, 3> strings{ a, b, c };
        array<char, 3> indexes{ 0, 1, 2 };
        string result = a + b + c;

        do {
            string nextResult = generateString(strings, indexes);

            if (nextResult.size() == result.size()) {
                result = min(result, nextResult);
            } else if (nextResult.size() < result.size()) {
                result = move(nextResult);
            }
        } while (next_permutation(indexes.begin(), indexes.end()));

        return result;
    }
private:
    string generateString(const array<reference_wrapper<string>, 3>& strings, const array<char, 3>& indexes) {
        string result = strings[indexes[0]];

        for (int i = 1; i < indexes.size(); ++i) {
            if (result.find(strings[indexes[i]]) != string::npos) { continue; }

            const auto& nextString = strings[indexes[i]].get();

            for (int len = min(nextString.size(), result.size()); len >= 0; --len) {
                if (equal(result.end() - len, result.end(), nextString.begin())) {
                    result.append(nextString, len);
                    break;
                }
            }
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