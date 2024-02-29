// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        m_stack.push(val);

        if (m_mins.empty() || val <= m_mins.top()) {
            m_mins.push(val);
        }
    }

    void pop() {
        if (m_stack.top() <= m_mins.top())
            m_mins.pop();

        m_stack.pop();
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_mins.top();
    }

private:
    stack<int> m_stack;
    stack<int> m_mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
