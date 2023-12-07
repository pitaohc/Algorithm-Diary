#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<array>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> box{}; // array 需要初始化
        bool result = true;
        for (char ch : s) {
            ++box[ch - 'a'];
        }
#ifdef _DEBUG
        fmt::print("box: {}\n", box);
#endif // _DEBUG
        for (char ch : t) {
            --box[ch - 'a'];
        }
#ifdef _DEBUG
        fmt::print("box: {}\n", box);
#endif // _DEBUG

        for (int count : box) {
            if (count != 0) {
                result = false;
                break;
            }
        }
        return result;
    }
};

