// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        Node() : nodes{ nullptr } {}
        Node* nodes[26];
    };

    Node root;
public:
    int minValidStrings(vector<string>& words, string target) {
        int sz = target.size();
        vector<int> dp(sz + 1, sz + 1);
        dp.back() = 0;

        for (auto& w : words) { addWord(w); }

        for (int i = sz - 1; i >= 0; --i) {
            Node* node = &root;
            int& val = dp[i];

            for (int j = i; j < sz; ++j) {
                node = node->nodes[target[j] - 'a'];
                if (!node) { break; }

                val = min(val, 1 + dp[j + 1]);
            }
        }

        return dp.front() <= sz ? dp.front() : -1;
    }
private:
    void addWord(string word) {
        Node* node = &root;

        for (char c : word) {
            int index = c - 'a';

            if (node->nodes[index] == nullptr) {
                node->nodes[index] = new Node();
            }

            node = node->nodes[index];
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}