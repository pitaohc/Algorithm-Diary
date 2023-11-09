#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0)
        {
            fmt::print("{}\n", n);
            n /= 3;
        }
        fmt::print("{}\n", n);
        return n == 1;
    }
};