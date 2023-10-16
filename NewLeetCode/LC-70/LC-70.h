#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        int num1 = 1, num2 = 1, num3;

        for (size_t i = 2; i <= n; i++)
        {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num2;
    }
};
