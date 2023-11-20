#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        x = x ^ y;
        while (x != 0)
        {
            distance += x & 1;
            x >>= 1;
        }

        return distance;
    }
};