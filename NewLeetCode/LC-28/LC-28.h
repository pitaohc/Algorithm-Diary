#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = -1, n = haystack.size(), p = needle.size();
        if (p == 0) return 0;
        vector<int> next;
        calNext(needle, next);
        for (int i = 0; i < n; ++i) {
            while (k > -1 && needle[k + 1] != haystack[i]) {
                k = next[k];
            }
            if (needle[k + 1] == haystack[i]) {
                ++k;
            }
            if (k == p - 1) {
                return i - p + 1;
            }
        }
        return -1;
    }
    void calNext(const string& needle, vector<int>& next) {
        int n = needle.size();
        next = vector<int>(n, -1);
        for (int i = 1, p = -1; i < n; ++i) { //p表示公共前缀后缀长度
            while (p > -1 && needle[p + 1] != needle[i]) { //回溯条件：长度不为-1,字符不匹配
                p = next[p]; //如果下一位不同，往前回溯
            }
            //if (needle[p + 1] == needle[i]) { //如果字符相同，更新p
            //    ++p;
            //}
            next[i] = p = p + (needle[p + 1] == needle[i]);
        }

    }
};
