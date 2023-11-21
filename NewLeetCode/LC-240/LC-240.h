#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            int num = matrix[i][j];
            if (num == target) {
                return true;
            }
            else if (num < target) {
                ++i; //向下移动
            }
            else {
                --j;//向左移动
            }
        }

        return false;
    }
};
