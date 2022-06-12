// LeetCode.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <chrono>
#include <random>
#include <numeric>
#include <functional>

// TODO: Reference additional headers your program requires here.

#define INIT_TIME(timerName) \
    auto timerName = std::chrono::steady_clock::now();

#define PRINT_ELAPSED(startTime) \
    std::cout << "elapsed: " << (std::chrono::steady_clock::now() - startTime).count() / 1000000 << "ms" << std::endl; \
    startTime = std::chrono::steady_clock::now();