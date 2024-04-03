// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class WordDictionary {
    struct Node {
        Node(char c = 0) : c(c), word(false), nodes{ nullptr } {};

        char c;
        bool word;
        Node* nodes[26];
    };
public:
    WordDictionary() {

    }

    void addWord(string word) {
        Node* node = &root;
        int sz = word.size();

        for (int i = 0; i < sz; ++i) {
            int idx = word[i] - 'a';
            if (!node->nodes[idx]) {
                node->nodes[idx] = new Node(word[i]);
            }
            node = node->nodes[idx];
        }

        node->word = true;
    }

    bool search(string word) {
        return search(word, &root, 0);
    }
private:
    bool search(const string& word, Node* node, int index) {
        if (index == word.size()) {
            return node->word;
        }

        bool result = false;

        if (word[index] == '.') {
            for (auto n : node->nodes) {
                result = result || (n && search(word, n, index + 1));
            }
        } else {
            int idx = word[index] - 'a';
            result = node->nodes[idx] && search(word, node->nodes[idx], index + 1);
        }

        return result;
    }

private:
    Node root;
};

int main() {
    INIT_TIME(timer);

    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    dict.search("pad");
    dict.search("bad");
    dict.search(".ad");
    dict.search("..");
    dict.addWord("da");
    dict.search("..");

    PRINT_ELAPSED(timer);
    return 0;
}
