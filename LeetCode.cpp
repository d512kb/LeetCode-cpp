// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Trie {
    struct Node {
        Node() : c(0), word(false), nodes{ nullptr } {}
        Node(char c) : c(c), word(false), nodes{ nullptr } {}

        char c;
        bool word;
        Node* nodes[26];
    };
public:
    Trie() {

    }

    void insert(string word) {
        int wordSize = word.size();
        Node* node = &root;

        for (int i = 0; i < wordSize; ++i) {
            int idx = word[i] - 'a';
            if (!node->nodes[idx]) {
                node->nodes[idx] = new Node(word[i]);
            }
            node = node->nodes[idx];
        }

        node->word = true;
    }

    bool search(string word) {
        return search(word, false);
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
private:
    bool search(const string& word, bool prefixOnly) {
        int wordSize = word.size();
        Node* node = &root;

        for (int i = 0; i < wordSize; ++i) {
            int idx = word[i] - 'a';
            if (!node->nodes[idx]) {
                return false;
            }
            node = node->nodes[idx];
        }

        return prefixOnly || node->word;
    }

private:
    Node root;
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
