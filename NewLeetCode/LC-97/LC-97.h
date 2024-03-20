#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    string s1, s2, s3;
    int size1, size2, size3;
    vector<vector<int>> dp;
    bool dfs(int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        if (i + j == size3) return true;
        bool res = false;
        if (i < size1 && s1[i] == s3[i + j]) {
            res |= dfs(i + 1, j);
        }
        if (j < size2 && s2[j] == s3[i + j]) {
            res |= dfs(i, j + 1);
        }
        dp[i][j] = res;
        return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->size1 = s1.size();
        this->size2 = s2.size();
        this->size3 = s3.size();
        this->dp = vector<vector<int>>(size1 + 1, vector<int>(size2 + 1, -1));
        return dfs(0, 0);
    }
};

