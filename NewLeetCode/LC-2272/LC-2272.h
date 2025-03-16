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
    int largestVariance(string s) {
        int maxDiff = 0;
        vector<vector<int>> f0(26, vector<int>(26, 0));
        vector<vector<int>> f1(26, vector<int>(26, INT_MIN));
        // 假设s中只出现a和b两种字符
        for (char ch : s) {
            ch -= 'a';
            for (int i = 0; i < 26; ++i) {
                if (i == ch) {
                    continue; // 排除a == b
                }
                // ch == a
                // 
                f0[ch][i] = max(f0[ch][i], 0) + 1;
                f1[ch][i]++;
                // ch == b
                f1[i][ch] = f0[i][ch] = max(f0[i][ch], 0) - 1;
                maxDiff = max(maxDiff, max(f1[ch][i], f1[i][ch]));
            }
        }

        return maxDiff;
    }
};

