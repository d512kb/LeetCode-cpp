// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int, int>, greater<>> freqMaxSet;
        set<pair<int, int>> freqMinSet;
        unordered_map<int, int> freqs;
        int64_t sum = 0;

        for (int i = 0; i < k; ++i) { ++freqs[nums[i]]; }
        for (const auto& s : freqs) { freqMaxSet.emplace(s.second, s.first); }
        for (int i = 0; i < x && !freqMaxSet.empty(); ++i) {
            auto node = freqMaxSet.extract(freqMaxSet.begin());
            sum += static_cast<int64_t>(node.value().first) * node.value().second;
            freqMinSet.insert(std::move(node));
        }

        vector<long long> result;
        result.push_back(sum);

        for (int prev = 0, next = k; next < nums.size(); ++prev, ++next) {
            auto prevNum = make_pair(freqs[nums[prev]]--, nums[prev]);
            auto nextNum = make_pair(freqs[nums[next]]++, nums[next]);

            auto iter = freqMinSet.find(prevNum);
            if (iter != freqMinSet.end()) {
                sum -= static_cast<int64_t>(prevNum.first) * prevNum.second;
                freqMinSet.erase(iter);
            } else {
                freqMaxSet.erase(prevNum);
            }

            freqMaxSet.emplace(prevNum.first - 1, prevNum.second);
            if (freqMinSet.size() < x) {
                auto node = freqMaxSet.extract(freqMaxSet.begin());
                sum += static_cast<int64_t>(node.value().first) * node.value().second;
                freqMinSet.insert(std::move(node));
            }

            iter = freqMinSet.find(nextNum);
            if (iter != freqMinSet.end()) {
                sum -= static_cast<int64_t>(nextNum.first) * nextNum.second;
                freqMinSet.erase(iter);
            } else {
                freqMaxSet.erase(nextNum);
            }

            freqMinSet.emplace(nextNum.first + 1, nextNum.second);
            sum += static_cast<int64_t>(nextNum.first + 1) * nextNum.second;
            if (freqMinSet.size() > x) {
                auto node = freqMinSet.extract(freqMinSet.begin());
                sum -= static_cast<int64_t>(node.value().first) * node.value().second;
                freqMaxSet.insert(std::move(node));
            }

            result.push_back(sum);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}