#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> us;
        for (const int num : nums) {
            us.insert(num);
        }
        const int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            if (us.find(i) == us.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};