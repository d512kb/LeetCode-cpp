// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Iterator {
public:
	Iterator(const vector<int>& nums) {};
	
	// Returns the next element in the iteration.
	int next() {};
	
	// Returns true if the iteration has more elements.
	bool hasNext() const {};
	
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), m_peekIterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

		m_peekValue = m_peekIterator.next();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return m_peekValue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (m_peekIterator.hasNext()) {
			m_peekValue = m_peekIterator.next();
		}
		return Iterator::next();
	}

	bool hasNext() const {
		return Iterator::hasNext();
	}
private:
	Iterator m_peekIterator;
	int m_peekValue;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}