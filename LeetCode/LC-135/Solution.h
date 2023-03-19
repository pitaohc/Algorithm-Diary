#pragma once
#include"stdc++.h"

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        using namespace std;
        int n = ratings.size();
        vector<int> candies(n, 1); //默认每人给一颗
        for (int i = 1; i < n; i++) //从左向右遍历
        {
            if (ratings[i - 1] < ratings[i]) //如果右边的小朋友评分更高
            {
                candies[i] = candies[i - 1] + 1; //他会比左边的小朋友多一颗
            }
        }
        //Warning: 倒序遍历如果边界为0不能使用size_t，
        //原因：size_t的本质是无符号整型，当i应为-1时它会变成一个正整数
        for (int i = n - 2; i >= 0; i--) //从右向左遍历
        {
            //如果左边的小朋友评分更高，而且他的糖果不大于右边的小朋友
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            {
                candies[i] = candies[i + 1] + 1;//他会比右边的小朋友多一颗
            }
        }
        int result = accumulate(candies.begin(), candies.end(), 0);
        return result;

    }
};