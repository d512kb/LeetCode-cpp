// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCount(26);
        for (char c : s) { ++charCount[c - 'a']; }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (charCount[i] > 0) {
                pq.emplace(charCount[i], i + 'a');
            }
        }

        string result;
        result.reserve(s.size());

        while (pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            result.push_back(p1.second);
            result.push_back(p2.second);
            if (--p1.first > 0) { pq.push(std::move(p1)); };
            if (--p2.first > 0) { pq.push(std::move(p2)); };
        }

        if (!pq.empty()) {
            if (pq.top().first > 1) { return ""; }

            result.push_back(pq.top().second);
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