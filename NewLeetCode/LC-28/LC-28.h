#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int p = -1, n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        vector<int> next;
        calNext(needle, next);
        for (int i = 0; i < n; ++i) {
            //结构和计算next数组类似
            while (p > -1 && needle[p + 1] != haystack[i]) {
                p = next[p];
            }
            p += (needle[p + 1] == haystack[i]);
            if (p == m - 1) { //如果遍历完needle，说明完全匹配
                return i - m + 1; //返回开始位置
            }
        }
        return -1;
    }
    void calNext(const string& needle, vector<int>& next) {
#ifdef _DEBUG
        fmt::print("p {}\n", needle);
#endif // _DEBUG

        int n = needle.size();
        next = vector<int>(n, -1);
        for (int i = 1, p = -1; i < n; ++i) { //p表示当前公共前缀后缀长度
            while (p > -1 && needle[p + 1] != needle[i]) { //回溯条件：长度不为-1,字符不匹配
                p = next[p]; //如果下一位不同，往前回溯
            }
            //if (needle[p + 1] == needle[i]) { //如果字符相同，更新p
            //    ++p;
            //}
            next[i] = p = p + (needle[p + 1] == needle[i]);
#ifdef _DEBUG
            fmt::print("i = {}, p = {}, next {}\n", i, p, next);
#endif
        }

    }
};
