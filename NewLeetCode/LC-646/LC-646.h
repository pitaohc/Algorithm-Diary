#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) {
            return 0;
        }
        const int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const auto& left, const auto& right) {
            return left[1] != right[1] ? left[1] < right[1] : left[0] < right[0];
            });
#ifdef _DEBUG
        fmt::print("{}\n", pairs);
#endif // _DEBUG
        int res = 1;
        int cur_num = pairs[0][1];
        for (const auto& pair : pairs) {
            if (pair[0] > cur_num) {
                ++res;
                cur_num = pair[1];
            }
        }
        return res;
    }
};

