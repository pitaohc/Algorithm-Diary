#pragma once
#include"stdc++.h"
#include"List.h"
#include"util.h"
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        using namespace std;
        int pos1 = m - 1, pos2 = n - 1, posResult = nums1.size() - 1;
        while (pos1 >= 0 && pos2 >= 0)
        {
            if (nums1[pos1] > nums2[pos2])
            {
                nums1[posResult--] = nums1[pos1--];
            }
            else
            {
                nums1[posResult--] = nums2[pos2--];
            }
        }
        while (pos1 >= 0 && posResult >= 0)
        {
            nums1[posResult--] = nums1[pos1--];
        }
        while (pos2 >= 0 && posResult >= 0)
        {
            nums1[posResult--] = nums2[pos2--];
        }
    }
};