//
// Created by devcpp on 23-8-15.
//

#ifndef LC_4_SOLUTION_H
#define LC_4_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
using namespace std;

class Solution {
    double findKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true)
        {
            //边界条件
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }

            //正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            const int& elem1 = nums1[newIndex1];
            const int& elem2 = nums2[newIndex2];

            if (elem1 <= elem2)
            {
                //元素1更小
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2)
        {
            return findKthElement(nums1, nums2, (size + 1) / 2);
        }
        else
        {
            return (findKthElement(nums1, nums2, size / 2) +
                findKthElement(nums1, nums2, size / 2 + 1)) / 2;
        }
    }
};
#endif //LC_4_SOLUTION_H
