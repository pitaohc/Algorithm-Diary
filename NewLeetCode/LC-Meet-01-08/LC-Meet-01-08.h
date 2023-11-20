#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        vector<bool> row(n, false), col(m, false);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (matrix[i][j]==0) {
                    row[i] = col[j] =true;
                }
            }
        }

        vector<int> zerosRow(m, 0);
        for (size_t i = 0; i < n; ++i) {
            if (row[i]) {
                matrix[i] = zerosRow;
            }
            else {
                for (size_t j = 0; j < m; j++)
                {
                    if (col[j]) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
