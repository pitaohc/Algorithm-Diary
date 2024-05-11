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
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) // �Դ��Ľ�βλ����Ϊ��ѭ��
        {
            dp[j][j] = 1; // ����Ϊ1�Ĵ�һ���ǻ����ַ���
            for (int i = j-1; i >=0; i--) // ע�����˳�򣬳��Ĵ������̵Ĵ���������Ҫ�������
            {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // ����ȵ����
                }
            }
        }
        return dp[0][n - 1];
    }
};
