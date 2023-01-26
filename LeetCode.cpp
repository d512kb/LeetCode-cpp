// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* next = nullptr) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode* a = head;
		ListNode* b = head;

		while (b != nullptr && b->next != nullptr) {
			a = a->next;
			b = b->next->next;

			if (a == b)
				break;
		}

		if (b == nullptr || b->next == nullptr)
			return nullptr;

		ListNode* nodeInLoop = b;
		a = head;
		b = b->next;

		if (nodeInLoop == nodeInLoop->next)
			return nodeInLoop;

		while (a != b) {
			a = a->next;
			b = b == nodeInLoop ? head : b->next;
		}

		return a;
	}
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
