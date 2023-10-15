#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        using ll = long long int;
        int n = grid.size(), m = grid[0].size();
        int mmod = 12345;
        vector<vector<int>> res(n, vector<int>(m, 1));
        ll sum = 1;
        for (int i = n - 1; i >= 0; i--) //计算后缀积
        {
            for (int j = m - 1; j >= 0; j--)
            {
                res[i][j] = sum;
                sum = (sum * grid[i][j]) % mmod;
            }
        }
        sum = 1;
        for (int i = 0; i < n; i++) //计算前缀积
        {
            for (int j = 0; j < m; j++)
            {
                res[i][j] = (res[i][j] * sum) % mmod;
                sum = (sum * grid[i][j]) % mmod;
            }
        }
        return res;
    }
};