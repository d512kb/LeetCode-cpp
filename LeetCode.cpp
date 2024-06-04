// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Node {
        Node() : w(false), nodes{ nullptr } {}
        bool w;
        Node* nodes[26];
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string& s : wordDict) {
            addWord(s);
        }

        m_indexes.assign(s.size(), 0);

        return checkString(s);
    }

private:
    Node root;
    vector<char> m_indexes;

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

    bool checkString(const string& s) {
        int sz = s.size();
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int qz = q.size();

            while (qz--) {
                int index = q.front();
                q.pop();

                if (index == sz)
                    return true;

                if (m_indexes[index]) { continue; }
                m_indexes[index] = 1;
                Node* node = &root;

                for (; index < sz; ++index) {
                    node = node->nodes[s[index] - 'a'];

                    if (!node)
                        break;

                    if (node->w) {
                        q.push(index + 1);
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    vector<string> dict{ "cats","dog","sand","and","cat","an" };
    bool r = sol.wordBreak("catsandogcat", dict);

    PRINT_ELAPSED(timer);
    return 0;
}
