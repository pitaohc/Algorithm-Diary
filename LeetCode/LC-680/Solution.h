#pragma once
#include"stdc++.h"
#include"List.h"
class Solution {

private:
    //判断子字符串是否回文
    bool checkPalindrome(const std::string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(std::string s) {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] == s[right]) //去除两端相同的部分
            {
                left++;
                right--;
            }
            else
            {
                //删除一个字符，再判断是否回文
                return checkPalindrome(s, left, right - 1) ||
                    checkPalindrome(s, left + 1, right);
            }
        }
        return true;
    }
};