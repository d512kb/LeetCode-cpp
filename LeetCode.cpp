// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        refillOutput();

        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        refillOutput();

        return output.top();
    }

    bool empty() {
        refillOutput();

        return output.empty();
    }
private:
    stack<int> input;
    stack<int> output;

    void refillOutput() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}