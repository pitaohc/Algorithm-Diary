#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result{ 0 };
        const size_t n{ arr.size() };
        int maxNum{ 0 }, minNum{ 0 }, begin{ 0 }, end{ 0 };
        bool newSub = true;
        for (size_t i = 0; i < n; i++)
        {

            end = i;
            maxNum = std::max(maxNum, arr[i]);
            minNum = std::min(minNum, arr[i]);
            if (maxNum == end && minNum == begin) {
                ++result;
                if (i + 1 < n) {
                    begin = end = i + 1;
                    maxNum = minNum = arr[i + 1];
                }
            }
        }
        return result;
    }
};

