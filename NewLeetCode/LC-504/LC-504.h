#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        const int MOD = 7;
        bool isNagitve = (num < 0);
        if (num == 0) return "0";
        string result;
        num = abs(num);
        while (num > 0)
        {
            result.push_back((char)((num % MOD) + '0'));
            num /= MOD;
        }
        if (isNagitve)
        {
            result.push_back('-');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
