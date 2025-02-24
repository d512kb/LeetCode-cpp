// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        bool w{ false };
        array<unique_ptr<Node>, 26> nodes{};
    };
public:
    Solution() : m_root(new Node()) {};

    string longestWord(vector<string>& words) {
        for (const string& word : words) { addWord(word); }

        string word;
        string longestWord;

        findLongestWords(m_root.get(), word, longestWord);

        return longestWord;
    }
private:
    unique_ptr<Node> m_root;

    void addWord(const string& word) {
        auto node = m_root.get();

        for (char c : word) {
            int idx = c - 'a';

            if (!node->nodes[idx]) { node->nodes[idx] = make_unique<Node>(); }
            node = node->nodes[idx].get();
        }

        node->w = true;
    }

    void findLongestWords(Node* node, string& word, string& longestWord) {
        for (int i = 0; i < 26; ++i) {
            if (node->nodes[i] && node->nodes[i]->w) {
                word.push_back(i + 'a');
                findLongestWords(node->nodes[i].get(), word, longestWord);
                word.pop_back();
            }
        }

        if (word.size() > longestWord.size() || (word.size() == longestWord.size() && word < longestWord)) {
            longestWord = word;
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}