#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto left_it = numbers.begin(), right_it = numbers.end() - 1;
        while (left_it != right_it) {
            int sum = *left_it + *right_it;
            if (sum == target) {
                break;
            }
            else if (sum < target) {
                ++left_it;
            }
            else {
                --right_it;
            }
        }


        return { static_cast<int>(left_it - numbers.begin() + 1), static_cast<int>(right_it - numbers.begin() + 1) };
    }
};