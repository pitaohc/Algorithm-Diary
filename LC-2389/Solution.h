#pragma once
#include<vector>

class Solution {
private:
    const int search(const std::vector<int>& preVect, const int query);
public:
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries);
};