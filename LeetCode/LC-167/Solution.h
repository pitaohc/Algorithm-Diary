#pragma once
#include"stdc++.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        using namespace std;
        vector<int> result(2, 0);
        result[1] = numbers.size() - 1;
        int& left = result[0], & right = result[1];
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                ++left;
                ++right;
                break;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }


        return result;
    }
};