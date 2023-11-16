#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;
        for (int i = 0; i < 32; i += 2) {
            if (n == (1 << i)) {
                return true;
            }
        }
        return false;
    }
};

