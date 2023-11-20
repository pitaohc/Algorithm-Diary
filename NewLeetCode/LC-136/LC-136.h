#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int num : nums)
        {
            result ^= num; //按位异或
            /*
            思考：
            假设只有1bit数据，我们需要找出n个1bit数据中出现一次的值
            异或：相同的值置零，不同的值置1
            那么 a^a = 0, a^a^0 = 0, a^a^1 = 1
            最后的结果只跟出现一次的值有关
            推广到32bit的数据，使用一个int存储结果，遍历数组进行异或运算，就可以得到出现一次的值
            */
        }
        return result;
    }
};
