#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0")
        {
            return num2;
        }
        else if (num2 == "0")
        {
            return num1;
        }
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int up = 0;
        string result;
        for (size_t i = 0; i < min(n, m); i++)
        {
            int n1 = num1[i] - '0';
            int n2 = num2[i] - '0';
            int temp = n1 + n2 + up;
            up = temp / 10;
            temp %= 10;
            result.push_back('0' + temp);
        }
        if (n > m)
        {
            for (size_t i = m; i < n; i++)
            {
                int n1 = num1[i] - '0';
                int temp = n1 + up;
                up = temp / 10;
                temp %= 10;
                result.push_back('0' + temp);
            }
        }
        else
        {
            for (size_t i = n; i < m; i++)
            {
                int n2 = num2[i] - '0';
                int temp = n2 + up;
                up = temp / 10;
                temp %= 10;
                result.push_back('0' + temp);
            }

        }
        if (up > 0)
        {
            result.push_back('0' + up);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
