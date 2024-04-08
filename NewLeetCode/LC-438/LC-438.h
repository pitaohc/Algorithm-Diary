#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<array>
using namespace std;
class Solution {
private:
    inline size_t getPos(char ch) {
        return ch - 'a';
    }
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size(), m = p.size();
        if (n < m) {
            return {};
        }
        array<int, 26> window{ 0 };
        int noZero = 0;
        for (int i = 0; i < m; ++i) {
            size_t pos = getPos(s[i]);
            ++window[pos];
            if (window[pos] == 1) {
                ++noZero;
            }
            else if (window[pos] == 0) {
                --noZero;
            }
        }
        for (const char& c : p) {
            size_t pos = getPos(c);
            --window[pos];
            if (window[pos] == -1) {
                ++noZero;
            }
            else if (window[pos] == 0) {
                --noZero;
            }
        }
#ifdef _DEBUG
        fmt::print("init status: {}\n", window);
#endif // _DEBUG

        vector<int> res;
        if (noZero == 0) {
            res.push_back(0);
        }
        for (int i = m; i < n; i++)
        {
            size_t pos = getPos(s[i - m]);
            --window[pos];
            if (window[pos] == -1) {
                ++noZero;
            }
            else if (window[pos] == 0) {
                --noZero;
            }
            pos = getPos(s[i]);
            ++window[pos];
            if (window[pos] == 1) {
                ++noZero;
            }
            else if (window[pos] == 0) {
                --noZero;
            }

            if (noZero == 0) {
                res.push_back(i - m + 1);
            }
#ifdef _DEBUG
            fmt::print("{}: {}\n", i, window);
#endif // _DEBUG
        }

        return res;
    }
};

