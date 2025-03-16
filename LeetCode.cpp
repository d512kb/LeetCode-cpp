// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for (; n > 0; --n) {
            string& str = result[n - 1];

            if (n % 3 == 0 && n % 5 == 0) { str = "FizzBuzz"; } else
                if (n % 3 == 0) { str = "Fizz"; } else
                    if (n % 5 == 0) { str = "Buzz"; } else
                        str = to_string(n);
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}