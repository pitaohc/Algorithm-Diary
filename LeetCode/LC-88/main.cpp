#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"List.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    vector<int> nums1, nums2;
    int n, m;

    //case1
    nums1 = { 1,2,3,0,0,0 };
    nums2 = { 2,5,6 };
    m = 3;
    n = 3;
    sol.merge(nums1, m, nums2, n);
    cout << nums1 << endl;
    return 0;
}