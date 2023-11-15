#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        for (int num : nums)
        {
            if (us.find(num) != us.end()) { //如果已经有元素存在则删除
                us.erase(num);
            }
            else //如果没有则添加
            {
                us.insert(num);
            }
        }
        return *us.begin(); //最后会剩下单个元素，直接返回
    }
};
