#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int last = 0, result = 0;
        auto it = s.begin();
        while (it != s.end()) {
            char ch = *it;
            int count = 0;
            while (it != s.end() && *it == ch) {
                ++count;
                ++it;
            }
            result += min(count, last);
            last = count;
        }
        return result;
    }
};
