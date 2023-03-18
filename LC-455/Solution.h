#pragma once
#include"stdc++.h"

class Solution {

public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        using namespace std;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int indexG = 0, indexS = 0;
        while (indexG < g.size() && indexS < s.size())
        {
            if (g[indexG] <= s[indexS]) //如果能满足小朋友胃口
            {
                ++indexG;
            }
            ++indexS;
        }
        return indexG;
    }
};