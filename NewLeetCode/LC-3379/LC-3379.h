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
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i=0;i < n;++i)
        {
            int index = ((i+nums[i]) % n + n ) % n;
            res[i] = nums[index];
        }
        
        return res;
    }
};
