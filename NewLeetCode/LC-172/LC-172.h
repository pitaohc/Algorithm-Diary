#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0) ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
