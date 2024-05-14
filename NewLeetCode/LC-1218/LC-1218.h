#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int n = arr.size();
        int res = 0;
        unordered_map<int,int> dp;
        dp.reserve(n);

        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            res = max(res, dp[num]);
        }

        return res;
    }
};

