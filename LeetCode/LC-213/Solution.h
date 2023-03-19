#pragma once
#include<vector>
using namespace std;
class Solution {
public:

    int rob(vector<int>& nums);
private:
    int rob(vector<int>& nums, int begin, int end);
};