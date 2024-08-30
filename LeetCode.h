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
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

// TODO: Reference additional headers your program requires here.

#define INIT_TIME(timerName) \
    auto timerName = std::chrono::steady_clock::now();

#define PRINT_ELAPSED(startTime) \
    std::cout << "elapsed: " << (std::chrono::steady_clock::now() - startTime).count() / 1000000 << "ms" << std::endl; \
    startTime = std::chrono::steady_clock::now();