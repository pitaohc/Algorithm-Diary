#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include<array>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //key的hash函数 接收一个key的类型作为参数，返回size_t作为hash值
        //fn作为闭包的外部参数，按值传入lambda表达式中
        //hash值的计算过程中，调用accumulate计算整个array的累计值，累加的过程调用自定义的lambda表达式
        auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
                });
            };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (const string& str : strs) {
            array<int, 26> counts{};
            int n = str.size();
            for (int i = 0; i < n; i++)
            {
                ++counts[str[i] - 'a'];
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> res;
        for (const auto& pair : mp) {
            res.emplace_back(pair.second);
        }
        return res;
    }
};
