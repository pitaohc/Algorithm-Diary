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
    int minSwaps(string s) {
        int n = s.size();
        int lastleft = n - 1;
        while (s[lastleft] != '[') {
            --lastleft;
        }
        int rightCnt = 0;
        int swapCnt = 0;
        for (int i = 0; i < lastleft; ++i) {
            char ch = s[i];
            if (ch == '[') {
                --rightCnt;
            }
            else if (ch == ']') {
                ++rightCnt;
                if (rightCnt > 0) {
                    s[lastleft] = ']';
                    s[i] = '[';
                    rightCnt = -1;
                    ++swapCnt;
                    //fmt::println("cnt: {},i: {}, {}", swapCnt, i, s);
                    while (i < lastleft && s[lastleft] != '[') {
                        --lastleft;
                    }

                }

            }

        }
        return swapCnt;
    }
};

