//
// Created by devcpp on 23-7-27.
//
#include"LC-69-Solution.h"
#include "stdc++.h"
#include <cmath>

using namespace std;

int main() {
    cout << "Leetcode 69. x 的平方根" << endl
         << "https://leetcode.cn/problems/sqrtx/" << endl;
    Solution sol;
    for (int i = 0; i < 10; ++i) {
        cout << "Case " << i
             << ", result = " << sol.mySqrt(i)
             << ", ground truth = " << (int) sqrt(i) << endl;
    }
    cout << "Case " << 2147395599
         << ", result = " << sol.mySqrt(2147395599)
         << ", ground truth = " << (int) sqrt(2147395599) << endl;
    return 0;
}