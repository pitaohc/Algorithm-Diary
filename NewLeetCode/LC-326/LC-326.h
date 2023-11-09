#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        constexpr int MAGICNUM = 1162261467;
        return n > 0 && MAGICNUM % n == 0;
    }
};