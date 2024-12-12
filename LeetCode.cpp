// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        bool word = false;
        Node* nodes[26]{};
    } m_root;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) { addWord(word); }

        vector<string> result;
        string str;

        auto parseString = [&](auto&& self, int index, Node* node) -> void {
            if (index == s.size()) {
                if (node->word) { result.push_back(str); }
                return;
            }

            node = node->nodes[s[index] - 'a'];
            if (!node) { return; }

            str.push_back(s[index]);

            if (node->word) {
                str.push_back(' ');
                self(self, index + 1, &m_root);
                str.pop_back();
            }

            self(self, index + 1, node);
            str.pop_back();
        };

        parseString(parseString, 0, &m_root);

        return result;
    }
private:
    void addWord(const string& word) {
        Node* node = &m_root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->nodes[idx]) {
                node->nodes[idx] = new Node();
            }

            node = node->nodes[idx];
        }

        node->word = true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}