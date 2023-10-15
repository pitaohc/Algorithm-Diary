#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        map<int, int> mp;
        for (size_t i = indexDifference; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n - indexDifference; i++)
        {
            int num1 = nums[i];
            int num2 = mp.begin()->first;
            if (abs(num1 - num2) < valueDifference) {
                mp[num2]--;
                if (mp[num2] == 0)
                {
                    mp.erase(num2);
                }
            }
            else {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] == num2) {
                        return { i,j };
                    }
                }
            }
        }
        return { -1,-1 };
    }
};
