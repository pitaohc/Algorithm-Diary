#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    vector<int> getNext(const string& str) {
        const int n = str.size();
        vector<int> next(n, -1);
        for (int i = 1, k = -1; i < n; ++i) { // 遍历每一个位置, k 代表前缀和后缀相同的长度-1
            while (k > -1 && str[i] != str[k + 1]) { //k+1代表前缀的位置，i代表后缀的位置
                k = next[k];
            }
            k = next[i] = k + (str[i] == str[k + 1]);
        }

        return next;
    }
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.size(), m = needle.size();
        const vector<int> next = getNext(needle);
#ifdef _DEBUG
        fmt::print("needle: {}\n"
            "next: {}\n", needle, next);
#endif // _DEBUG

        int result = -1;
        for (int i = 0, k = -1; i < n; ++i) {
            while (k > -1 && haystack[i] != needle[k + 1]) {
                k = next[k];
            }
            if (haystack[i] == needle[k + 1]) {
                ++k;
            }
            if (k == m - 1) {
                result = i - m + 1; //得到头位置
                break;
            }
        }

        return result;
    }
};
