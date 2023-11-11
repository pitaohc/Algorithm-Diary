#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    vector<int> weights;
public:
    Solution(vector<int>& w) {
        int sumWeight = 0;
        weights.reserve(w.size());
        for (const int& weight : w)
        {
            sumWeight += weight;
            weights.push_back(sumWeight);
        }
    }

    int pickIndex() {
        int pos = rand() % weights.back() + 1;
        return lower_bound(weights.begin(), weights.end(), pos) - weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
