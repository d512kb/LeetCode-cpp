// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        Node() : word(false), nodes{ nullptr } {};
        bool word;
        Node* nodes[26];
    };

    void addWord(const string& word) {
        Node* node = &root;

        for (char c : word) {
            int idx = c - 'a';
            if (!node->nodes[idx])
                node->nodes[idx] = new Node();

            node = node->nodes[idx];
        }

        node->word = true;
    }

    Node* getNode(Node* node, char c) {
        return node->nodes[c - 'a'];
    }

    Node root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board.front().size();
        string word;
        vector<string> result;

        for (const string& word : words) {
            addWord(word);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                processCell(board, i, j, rows, cols, word, &root, result);
            }
        }

        return result;
    }
private:
    void processCell(vector<vector<char>>& board, int i, int j, int rows, int cols, string& word, Node* node, vector<string>& result) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || !board[i][j] || !getNode(node, board[i][j]))
            return;

        char ch = board[i][j];
        board[i][j] = 0;
        word.push_back(ch);
        node = getNode(node, ch);

        if (node->word) {
            result.push_back(word);
            node->word = false;
        }

        processCell(board, i, j + 1, rows, cols, word, node, result);
        processCell(board, i + 1, j, rows, cols, word, node, result);
        processCell(board, i, j - 1, rows, cols, word, node, result);
        processCell(board, i - 1, j, rows, cols, word, node, result);

        board[i][j] = ch;
        word.pop_back();
    }
};

int main() {
    INIT_TIME(timer);

    vector<vector<char>> board {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words{"oath","pea","eat","rain" };

    Solution sol;
    auto w = sol.findWords(board, words);

    PRINT_ELAPSED(timer);
    return 0;
}
