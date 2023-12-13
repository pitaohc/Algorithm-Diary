#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    const int countSubstrings(string& s, int left, int right) {
        const int n = s.size();
        int count = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            --left;
            ++right;
            ++count;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += countSubstrings(s, i, i);
            result += countSubstrings(s, i, i+1);
        }
        return result;
    }
};

