//
// Created by devcpp on 23-7-27.
//

#ifndef LC_69_SOLUTION_H
#define LC_69_SOLUTION_H

#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = std::min(x, 65535), mid;
        constexpr short DIV = 10; //为了更快逼近结果，更优的方法是使用泰勒级数展开的牛顿迭代法
        while (left < right) {
            mid = (right - left) / DIV + left;
            long long int pow_mid = (long long int) mid * mid;
            if (pow_mid == x or pow_mid < x and (pow_mid + 2 * mid + 1 > x)) {
                return mid;
            } else if (pow_mid < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

#endif //LC_69_SOLUTION_H
