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
    string crackSafe(int n, int k) {
        const int kn = std::pow(k, n), kn_1 = std::pow(k, n - 1);
        vector<int> nums(kn_1, k - 1);
        string result(kn + n - 1, '0');
        for (int i = n - 1, node = 0; i < kn + n - 1; ++i) {
            result[i] = nums[node] + '0'; //走过路径，修改字符串
            --nums[node]; // 当前节点最大序号-1
            node = node * k - (result[i - n + 1] - '0') * kn_1 + nums[node] + 1; // 更新当前节点
        }
        return result;
    }
};
