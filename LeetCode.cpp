// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) : m_data(n) {

    }

    vector<string> insert(int idKey, string value) {
        m_data[idKey - 1] = std::move(value);

        vector<string> result;

        for (; m_pointer < m_data.size() && !m_data[m_pointer].empty(); ++m_pointer) {
            result.push_back(std::move(m_data[m_pointer]));
        }

        return result;
    }
private:
    vector<string> m_data;
    size_t m_pointer = 0;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}