#pragma once
#include"stdc++.h"
#include"List.h"
class Solution {
public:
    bool judgeSquareSum(int c) {
        int end = sqrt(c);

        //遍历a
        for (size_t a = 0; a <= end; a++) //使用long避免了int溢出
        {
            int b2 = c - a * a; //计算差值
            int b = sqrt(b2);
            if (b * b == b2) return true; //判断b2的平方根是否是整数
        }

        return false;
    }
};