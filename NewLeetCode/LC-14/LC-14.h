#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int n = strs.size();
        if (n == 0)
        {
            return string();
        }
        if (n == 1)
        {
            return strs[0];
        }
        int min_size = strs[0].size();
        for (const string& str : strs) {
            min_size = min(min_size, static_cast<int>(str.size()));
        }
        int pos = 0;
        for (size_t i = 0; i < min_size; i++)
        {
            char ch = strs[0][i];
            for (const string& str : strs)
            {
                if (ch != str[i])
                {
                    return str.substr(0, pos);
                }
            }
            ++pos;
        }
        return strs[0].substr(0, pos);
    }
};
