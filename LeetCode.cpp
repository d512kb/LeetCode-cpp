// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Compare {
        bool operator()(const auto& p1, const auto& p2) const {
            return p1.second > p2.second;
        }
    };
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int wordSize = beginWord.size();
        unordered_map<string, pair<int, vector<string>>> distances;

        for (auto& word : wordList) { distances.emplace(word, make_pair(numeric_limits<int>::max(), vector<string>())); }
        distances[beginWord].first = 0;

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        pq.emplace(beginWord, 0);

        while (!pq.empty()) {
            auto currentNode = pq.top();
            auto word = currentNode.first;
            pq.pop();

            for (int i = 0; i < wordSize; ++i) {
                char prevC = word[i];

                for (int c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    auto iter = distances.find(word);

                    if (iter != distances.end()) {
                        int newCost = currentNode.second + 1;

                        if (newCost < iter->second.first) {
                            iter->second = make_pair(newCost, vector<string>(1, currentNode.first));
                            pq.emplace(word, newCost);
                        } else if (newCost == iter->second.first) {
                            iter->second.second.push_back(currentNode.first);
                        }
                    }
                }

                word[i] = prevC;
            }
        }

        vector<vector<string>> result;

        if (!distances[endWord].second.empty()) {
            vector<string> path(1, endWord);
            buildPaths(distances, endWord, path, result);

            for (auto& path : result) {
                reverse(path.begin(), path.end());
            }
        }

        return result;
    }
private:
    void buildPaths(unordered_map<string, pair<int, vector<string>>>& distances, string word, vector<string>& path, vector<vector<string>>& result) {
        if (distances[word].second.empty()) { result.push_back(path); return; }

        for (auto& fromWord : distances[word].second) {
            path.push_back(fromWord);
            buildPaths(distances, fromWord, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}