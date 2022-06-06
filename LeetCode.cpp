// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x, ListNode* next = nullptr) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        int lengthA = 0;
        int lengthB = 0;

        while (a->next && b->next) {
            a = a->next;
            b = b->next;
            ++lengthA;
            ++lengthB;
        }

        while (a->next) {
            a = a->next;
            ++lengthA;
        }

        while (b->next) {
            b = b->next;
            ++lengthB;
        }

        if (a == b) {
            a = headA;
            b = headB;

            while (lengthA > lengthB) {
                a = a->next;
                --lengthA;
            }

            while (lengthB > lengthA) {
                b = b->next;
                --lengthB;
            }

            while (a != b) {
                a = a->next;
                b = b->next;
            }

            return a;
        }

        return nullptr;
    }
    ListNode* getIntersectionNodeFast(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }

        return a;
    }
};

int main() {

    Solution sol;

    ListNode* head = new ListNode(0);
    ListNode* head2 = new ListNode(-100000);// head;// new ListNode(-100000);
    
    const int n = 1000000;

    for (size_t i = 0; i < n; i++) {
        head = new ListNode(i, head);
        head2 = new ListNode(i-n, head2);
    }

    head2 = new ListNode(2323424, head2);
    
    int64_t sum = numeric_limits<int>::max();
    
    for (size_t i = 0; i < 10; i++) {
        auto start = chrono::steady_clock::now();
        cout << sol.getIntersectionNode(head, head2) << endl;
        sum = min(sum, (chrono::steady_clock::now() - start).count());
    }
    
    cout << sum / 100000 << endl << endl;

    sum = numeric_limits<int>::max();

    for (size_t i = 0; i < 10; i++) {
        auto start = chrono::steady_clock::now();
        cout << sol.getIntersectionNodeFast(head, head2) << endl;
        sum = min(sum, (chrono::steady_clock::now() - start).count());
    }

    cout << sum / 100000;
    
    return 0;
}
