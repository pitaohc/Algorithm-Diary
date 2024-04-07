#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = s.size(), m = t.size();
        if (n == 0) {
            return true;
        }
        else if (n > m) {
            return false;
        }
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == n;
    }
};

