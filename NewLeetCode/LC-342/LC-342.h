#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && //n是正数
            (n & (n - 1)) == 0 && // n是2的幂 
            (n & 0b10101010101010101010101010101010) == 0; //n是2的偶数次幂
    }
};

