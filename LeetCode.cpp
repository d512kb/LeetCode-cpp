// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> letters;
        for (auto& str : arr) {
            bitset<26> chars;

            for (char c : str) { chars.set(c - 'a'); }
            if (chars.count() == str.size()) { letters.push_back(std::move(chars)); }
        }

        bitset<26> str;
        return count(letters, 0, str);
    }
private:
    size_t count(const vector<bitset<26>>& letters, int i, bitset<26>& str) {
        if (i == letters.size()) { return str.count(); }

        size_t result = count(letters, i + 1, str);

        if ((str & letters[i]) == 0) {
            str |= letters[i];
            result = max(result, count(letters, i + 1, str));
            str &= ~letters[i];
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