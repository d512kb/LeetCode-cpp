// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreqs{ {"", 0} };
        for (const string& word : words) { ++wordFreqs[word]; }

        using WordPair = pair<string, int>;
        auto cmp = [](const WordPair& p1, const WordPair& p2) {
            if (p1.second == p2.second) { return p1.first < p2.first; }
            return p1.second > p2.second;
        };

        priority_queue<WordPair, vector<WordPair>, decltype(cmp)> pq;

        for (auto& freq : wordFreqs) {
            pq.push(freq);
            if (pq.size() > k) { pq.pop(); }
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
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