// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;

		int I = 0;
		int X = 0;
		int C = 0;

		for (const auto& c: s) {
			switch (c) {
			case 'I':
				I = 1;
				result += 1;
				break;
			case 'V':
				result += 5 - 2 * I;
				I = 0;
				break;
			case 'X':
				X = 10 * (1 - I);
				result += 10 - 2 * I;
				I = 0;
				break;
			case 'L':
				result += 50 - 2 * X;
				I = 0;
				X = 0;
				break;
			case 'C':
				C = 100 * (1 - X / 10);
				result += 100 - 2 * X;
				I = 0;
				X = 0;
				break;
			case 'D':
				result += 500 - 2 * C;
				I = 0;
				X = 0;
				C = 0;
				break;
			case 'M':
				result += 1000 - 2 * C;
				I = 0;
				X = 0;
				C = 0;
				break;
			}
		}

		return result;
	}
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
