#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        vector<int> layer(1, triangle[0][0]);
        for (int i = 1; i < n; ++i) {
            vector<int> cur_layer(i + 1);
            cur_layer[0] = layer[0] + triangle[i][0]; // 第一个元素
            for (int j = 1; j < i; j++)
            {
                cur_layer[j] = min(layer[j - 1], layer[j]) + triangle[i][j];
            }
            cur_layer[i] = layer[i - 1] + triangle[i][i];
#ifdef _DEBUG
            fmt::print("layer {}: {}\n", i, cur_layer);
#endif // _DEBUG

            layer = move(cur_layer);
        }
        return *min_element(layer.begin(), layer.end());
    }
};