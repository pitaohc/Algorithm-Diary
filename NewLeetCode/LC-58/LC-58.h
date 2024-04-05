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
    int lengthOfLastWord(string s) {
        const int n = s.size();
        int res = 0;
        int i = n - 1;
        while (i>=0 && s[i] == ' ') {
            --i;
        }
        while (i>=0 && s[i] != ' ') {
            --i;
            ++res;
        }
        return res;
    }
};

