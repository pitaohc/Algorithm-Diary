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
    vector<int> findOriginalArray(vector<int>& changed) {
        const int n = changed.size();
        if (n % 2) {
            return {};
        }
        sort(changed.begin(), changed.end());
        unordered_map<int, size_t> counts;
        for (const int num : changed) {
            counts[num]++;
        }
        vector<int> result;
        result.reserve(n / 2);
        for (const int num : changed) {
            if (counts[num] == 0) {
                continue;
            }
            if (counts[num * 2] <= 0) {
                return {};
            }
            --counts[num];
            --counts[num * 2];
            result.push_back(num);
        }
        return result;
    }
};
