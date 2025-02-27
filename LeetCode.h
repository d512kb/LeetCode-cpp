// LeetCode.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define INIT_TIME(timerName) \
    auto timerName = std::chrono::steady_clock::now();

#define PRINT_ELAPSED(startTime) \
    std::cout << "elapsed: " << (std::chrono::steady_clock::now() - startTime).count() / 1000000 << "ms" << std::endl; \
    startTime = std::chrono::steady_clock::now();