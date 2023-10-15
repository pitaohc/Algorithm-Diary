#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {

public:
    //第二个字符串是否小于第一个字符串
    bool isLess(const string& s, int begin1, int end1, int begin2, int end2) {
        int n1 = end1 - begin1;
        int n2 = end2 - begin2;
        if (n1 != n2) {
            return n2 < n1;
        }
        while (begin1 <= end1)
        {
            if (s[begin1] != s[begin2]) {
                return s[begin2] < s[begin1];
            }
            ++begin1;
            ++begin2;
        }
        return false;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int begin = 0, end = 0;
        int ansBegin = 0, ansEnd = 0;
        int cnt = 0;
        //去除前导0
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                begin = i;
                end = i;
                break;
            }
        }
        for (size_t i = begin; i < s.size(); i++) //i为开头
        {
            if (s[i] != '1')
            {
                continue;
            }

            if (cnt < k) { //还没找到第一个解的情况
                ++cnt;
                if (cnt == k) {
                    end = i;
                    ansBegin = begin;
                    ansEnd = end;
                }
            }
            else {
                int j = begin + 1; //寻找新的子串
                while (j < i && s[j] != '1')
                {
                    ++j;
                }
                begin = j;
                if (isLess(s, ansBegin, ansEnd, j, i)) {
                    ansBegin = j;
                    ansEnd = i;
                }
            }
        }
        if (cnt >= k)
        {
            return s.substr(ansBegin, ansEnd - ansBegin + 1);
        }
        else
        {
            return "";
        }
    }
};