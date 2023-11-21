#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const vector<int> direction = { {-1,1} };
        const int n = mat.size(), m = mat[0].size();
        vector<int> result;
        result.reserve(n * m);
        int level = 0;
        int i = 0, j = 0;
        int flag = 1;
        while (level < n + m - 1)
        {
            result.push_back(mat[i][j]);

            //尝试更新位置
            i += flag * direction[0];
            j += flag * direction[1];

            if (i < 0 || i >= n || j < 0 || j >= m) { //如果位置不合法
                flag = -flag; //转换方向
                ++level; //层次+1
                if (j >= m) { //右边界
                    i += 2;
                    j = m - 1;
                }
                else if (i < 0) //上边界
                {
                    i = 0;
                }
                else if (i >= n) { //下边界
                    i = n - 1;
                    j += 2;
                }
                else //左边界
                {
                    j = 0;
                }
            }
        }

        return result;

    }
};

