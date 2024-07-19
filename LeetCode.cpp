// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        Node() : w(false), nodes{ nullptr } {};
        bool w;
        Node* nodes[26];
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (auto& product : products) {
            addWord(product);
        }

        vector<vector<string>> result;
        vector<string> foundWords;
        Node* node = &root;
        string word;

        for (char c : searchWord) {
            word.push_back(c);
            int idx = c - 'a';

            if (node) { node = node->nodes[idx]; }
            if (node) { findThreeProducts(node, word, foundWords); }

            result.push_back(move(foundWords));
        }

        return result;
    }
private:
    void addWord(const string& word) {
        Node* node = &root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->nodes[idx]) {
                node->nodes[idx] = new Node();
            }

            node = node->nodes[idx];
        }

        node->w = true;
    }

    void findThreeProducts(Node* node, string& word, vector<string>& result) {
        if (result.size() == 3) { return; }
        if (node->w) { result.push_back(word); }

        for (int i = 0; i < 26; ++i) {
            if (node->nodes[i]) {
                word.push_back(i + 'a');
                findThreeProducts(node->nodes[i], word, result);
                word.pop_back();
            }
        }
    }

    Node root;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}