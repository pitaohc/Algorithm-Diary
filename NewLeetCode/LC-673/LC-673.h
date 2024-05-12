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
        for (int i = 0; i < n; i++) // iָ�����е�ĩβ
        {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) { // �������
                    if (dp[j] + 1 > dp[i]) { // �������
                        dp[i] = dp[j] + 1; // ���³���
                        cnt[i] = cnt[j]; // ���¸���
                    }
                    else if (dp[j] +1 == dp[i]) { // ���һ����
                        cnt[i] += cnt[j]; // ׷�Ӹ���
                    }
                }
            }
            if (dp[i] > maxSize) { // �����Ŀǰ������л�Ҫ��
                maxSize = dp[i]; // ���³���
                res = cnt[i]; // ���¸���
            }
            else if (dp[i] == maxSize) { //���һ����
                res += cnt[i]; //׷�Ӹ���
            }
        }

        return res;
    }
};

