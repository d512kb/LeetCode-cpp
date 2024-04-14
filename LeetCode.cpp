// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* node = head;
        ListNode preHead;
        int nodesCount = 0;

        while (node) {
            ++nodesCount;
            node = node->next;
        }

        return sortList(head, &preHead, nodesCount);
    }
private:
    ListNode* sortList(ListNode* node, ListNode* preHead, int nodesCount) {
        if (nodesCount == 1) {
            node->next = nullptr;
            return node;
        }

        int mid = nodesCount / 2;
        auto half = node;

        for (int i = 0; i < mid; ++i) {
            half = half->next;
        }

        ListNode* left = sortList(node, preHead, mid);
        ListNode* right = sortList(half, preHead, nodesCount - mid);

        ListNode* newHead = preHead;

        while (left && right) {
            if (left->val < right->val) {
                preHead->next = left;
                left = left->next;
            } else {
                preHead->next = right;
                right = right->next;
            }

            preHead = preHead->next;
        }

        if (left) {
            preHead->next = left;
        } else {
            preHead->next = right;
        }

        return newHead->next;
    }
};

int main() {
    INIT_TIME(timer);

    vector<ListNode> v{ 4,2,1,3 };

    for (int i = 0; i < v.size() - 1; ++i) {
        v[i].next = &v[i+1];
    }   

    Solution sol;
    auto sorted = sol.sortList(&v[0]);

    PRINT_ELAPSED(timer);
    return 0;
}
