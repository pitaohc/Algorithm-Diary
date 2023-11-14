#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    const uint32_t M1 = 0b01010101010101010101010101010101;
    const uint32_t M2 = 0b00110011001100110011001100110011;
    const uint32_t M4 = 0b00001111000011110000111100001111;
    const uint32_t M8 = 0b00000000111111110000000011111111;
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 1 & M1) | (n & M1) << 1;
        // abcdefgh -> 0a0c0e0g | b0d0f0h0 -> ba dc fe hg
        n = (n >> 2 & M2) | (n & M2) << 2;
        // badcfehg -> 00ba00fe | dc00hg00 -> dcba hgfe
        n = (n >> 4 & M4) | (n & M4) << 4;
        // dcbahgfe -> 0000dcba | hgfe0000 -> hgfedcba
        n = (n >> 8 & M8) | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};
