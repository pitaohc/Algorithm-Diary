#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (size_t i = 0; i < 32; i++)
        {
            result = (result << 1) | (n & 1); //result左移一位，把最低为置为n的最低位
            n >>= 1;
        }
        return result;
    }
};
