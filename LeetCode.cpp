// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string result;
        int from = 0;
        int to = 0;

        while ((to = sentence.find(' ', from)) != string::npos) {
            auto val = parsePrice(sentence, from, to);

            if (val && val.value() > 0) {
                result.append(format("${:.2f} ", val.value() * (100 - discount) / 100));
            } else {
                result.append(sentence.data() + from, to - from + 1);
            }

            from = to + 1;
        }

        auto val = parsePrice(sentence, from, sentence.size());
        if (val && val.value() > 0) {
            result.append(format("${:.2f}", val.value() * (100 - discount) / 100));
        } else {
            result.append(sentence.data() + from, sentence.size() - from);
        }

        return result;
    }
private:
    std::optional<double> parsePrice(const string& str, int from, int to) {
        if (str.empty() || str[from] != '$') { return nullopt; }

        double result = 0;
        if (from_chars(1 + str.data() + from, str.data() + to, result, std::chars_format::fixed).ptr == &str[to]) {
            return result;
        }

        return nullopt;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}