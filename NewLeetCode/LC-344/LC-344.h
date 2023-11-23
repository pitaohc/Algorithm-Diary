#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = s.size();
        for (int i = 0; i < n/2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
};

