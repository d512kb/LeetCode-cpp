// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        sort(word.begin(), word.end());

        size_t i = 0;
        vector<int> frequencies;
        frequencies.reserve(100);

        while (i < word.size()) {
            frequencies.push_back(countFrequency(word, i));
        }

        sort(frequencies.begin(), frequencies.end());

        if (frequencies[0] == 1) {
            if (frequencies[1] == 1) {
                --frequencies.back();
            } else {
                --frequencies[0];
            }
        } else {
            --frequencies.back();
        }

        int targetFreq = frequencies[0] == 0 ? frequencies[1] : frequencies[0];

        for (const auto& freq : frequencies) {
            if (freq != 0 && freq != targetFreq) {
                return false;
            }
        }

        return true;
    }

private:
    size_t countFrequency(const string& word, size_t& startIndex) {
        if (startIndex >= word.size()) {
            return -1;
        }

        char ch = word[startIndex];
        size_t result{ 0 };

        while (startIndex < word.size() && word[startIndex] == ch) {
            ++result;
            ++startIndex;
        }

        return result;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
