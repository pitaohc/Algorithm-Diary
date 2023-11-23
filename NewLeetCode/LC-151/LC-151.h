#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    void reverse(string& s)
    {
        const int n = s.size();
        for (int i = 0; i < n / 2; ++i)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
public:
    string reverseWords(string s) {
        const int n = s.size();
        reverse(s);
        int index = 0; //当前待写入位置
        fmt::print("reversed: .{}.\n", s);
        for (int start = 0; start < n; ++start)
        {
            if (s[start] == ' ') { //排除空格
                continue;
            }

            if (index != 0) s[index++] = ' ';//添加与前一个单词的空格

            int end = start;
            while (end < n && s[end] != ' ') //按倒序复制word
            {
                s[index++] = s[end++];
            }

            for (int i = 0; i < (end - start) / 2; ++i) { //反转回正常的word
                swap(s[index - i - 1], s[index - end + start + i]);
            }
            start = end; //更新start位置
        }
        s.erase(s.begin() + index, s.end());//删除后面多余字符

        return s;

    }
};
