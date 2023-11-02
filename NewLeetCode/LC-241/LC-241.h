#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    string expression;
    int toInt(int begin, int end)
    {
        int result = 0;
        while (begin < end)
        {
            result = result * 10 + expression[begin] - '0';
            ++begin;
        }
        return result;
    }
    vector<int> diffWaysToCompute(int begin, int end) //左闭右开
    {
        vector<int> result;
        size_t n = end - begin;
        for (size_t i = begin; i < end; i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(begin, i);
                vector<int> right = diffWaysToCompute(i + 1, end);
                for (const int& l : left)
                {
                    for (const int& r : right)
                    {
                        switch (c)
                        {
                        case '+':
                            result.push_back(l + r);
                            break;
                        case '-':
                            result.push_back(l - r);
                            break;
                        case '*':
                            result.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        if (result.empty()) result.push_back(toInt(begin, end)); //如果是纯数字则返回这个数字,此处做了重复性工作
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        this->expression = expression;
        return diffWaysToCompute(0, this->expression.size());
    }
};

