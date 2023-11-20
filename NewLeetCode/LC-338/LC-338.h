#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            results[i] = results[i >> 1] + (i & 1); //最低有效位
        }
        return results;
    }
};
