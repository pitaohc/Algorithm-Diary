//
// Created by devcpp on 23-8-15.
//

#ifndef LC_215_SOLUTION_H
#define LC_215_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
using namespace std;
class Solution {
private:
    //找第k小的元素 k in [0,n-1]
    void quickSort(vector<int>& nums, int k, int left, int right) {
        if (left + 1 >= right) {
            return;
        }
        int first = left, last = right - 1,
            index = rand() % (right - left) + left; //随机选取避免有序数组导致快排退化
        swap(nums[first], nums[index]);
        const int key = nums[first];
        while (first < last) {
            while (first < last && key <= nums[last]) {
                --last;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= key) {
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        if (first == k) { //恰好找到第k小的元素
            return;
        }
        else if (first > k) { //k在左区间
            quickSort(nums, k, left, first);
        }
        else { //k在右区间
            quickSort(nums, k, first + 1, right);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        quickSort(nums, nums.size() - k, 0, nums.size());
        return nums[nums.size() - k];
    }
};

#endif //LC_215_SOLUTION_H
