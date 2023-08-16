//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/color.h>
#include "LC-4-Solution.h"
using namespace std;

vector<int> merge(const vector<int>& nums1, const vector<int>& nums2)
{
    vector<int> result = nums1;
    //result.emplace_back(nums2);
    result.insert(result.end(), nums2.begin(), nums2.end());
    sort(result.begin(), result.end());
    return result;
}

void printResult(double ans, double res)
{
    if (res < ans + 0.01f && res > ans - 0.01f)
        //设置fmt颜色为绿色
        fmt::print(fg(fmt::color::green), "Passed\n");

    else
        fmt::print(fg(fmt::color::red), "Failed\n");

}

void printData(const vector<int>& nums1, const vector<int>& nums2, const double ans, const double res)
{
    static int caseNum = 0;
    caseNum++;
    fmt::print("Case {}\n"
        "nums1 = {}, nums2 = {}\n"
        "merged = {}\n"
        "ans = {:.2f}, res = {:.2f}\n",
        caseNum, nums1, nums2, merge(nums1, nums2), ans, res);

}

int main() {
    vector<int> nums1, nums2;
    double ans, res;
    Solution sol;

    nums1 = { 1,3 };
    nums2 = { 2 };
    ans = 2.0f;
    res = sol.findMedianSortedArrays(nums1, nums2);
    printData(nums1, nums2, ans, res);
    printResult(ans, res);
    fmt::print("\n");

    nums1 = { 1 };
    nums2 = { 2 };
    ans = 1.5f;
    res = sol.findMedianSortedArrays(nums1, nums2);
    printData(nums1, nums2, ans, res);
    printResult(ans, res);
    fmt::print("\n");

    nums1 = { 1,2,3,4 };
    nums2 = { 5,6,7,8,9 };
    ans = 5.0f;
    res = sol.findMedianSortedArrays(nums1, nums2);
    printData(nums1, nums2, ans, res);
    printResult(ans, res);
    fmt::print("\n");
    return 0;
}