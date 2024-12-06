// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class StreamChecker {
    struct Node {
        bool w = false;
        Node* nodes[26]{};
    };
public:
    StreamChecker(vector<string>& words) {
        for (auto& word : words) { addWord(word); }
    }

    bool query(char letter) {
        m_nodesToCheck.push_back(&m_root);

        auto iter = m_nodesToCheck.begin();
        int idx = letter - 'a';
        bool ans = false;

        while (iter != m_nodesToCheck.end()) {
            auto& node = *iter;
            node = node->nodes[idx];

            if (!node) {
                iter = m_nodesToCheck.erase(iter);
            } else {
                ans = ans || node->w;
                ++iter;
            }
        }

        return ans;
    }

private:
    Node m_root;

    void addWord(const string& word) {
        Node* node = &m_root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->nodes[idx] == nullptr) {
                node->nodes[idx] = new Node();
            }

            node = node->nodes[idx];
        }

        node->w = true;
    }

    list<Node*> m_nodesToCheck;
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}