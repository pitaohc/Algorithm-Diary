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
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 0), cnt(n, 0);
        int maxSize = 0, res = 0;
        for (int i = 0; i < n; i++) // i指向序列的末尾
        {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) { // 如果递增
                    if (dp[j] + 1 > dp[i]) { // 如果更长
                        dp[i] = dp[j] + 1; // 更新长度
                        cnt[i] = cnt[j]; // 更新个数
                    }
                    else if (dp[j] +1 == dp[i]) { // 如果一样长
                        cnt[i] += cnt[j]; // 追加个数
                    }
                }
            }
            if (dp[i] > maxSize) { // 如果比目前的最长序列还要长
                maxSize = dp[i]; // 更新长度
                res = cnt[i]; // 更新个数
            }
            else if (dp[i] == maxSize) { //如果一样长
                res += cnt[i]; //追加个数
            }
        }

        return res;
    }
};

