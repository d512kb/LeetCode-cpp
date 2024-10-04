// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) { minHeap.pop(); }
        }

        if (k > nums.size()) { minHeap.push(numeric_limits<int>::min()); }
    }

    int add(int val) {
        if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<>> minHeap;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}