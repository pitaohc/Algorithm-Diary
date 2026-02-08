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
    int minimumDeletions(const string& s) {
        int leftb = 0, righta = 0;
        for (const char& c : s)
        {
            righta += c == 'a';
        }
        
        int res = righta;
        for (const char& c : s)
        {
            if (c == 'a')
            {
                --righta;
            }else
            {
                ++leftb;
            }
            res = min(res,leftb + righta);
        }
        return res;
    }
};
