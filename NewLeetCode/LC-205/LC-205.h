#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> ums;
        unordered_map<char, int> umt;
        const int n = s.size();
        bool result = true;
        for (int i = 0; i < n; ++i) {
            if (ums.find(s[i]) != ums.end() &&
                umt.find(t[i]) != umt.end()) { // 两边都出现过
                if (ums[s[i]] == umt[t[i]]) {  // 如果出现的位置相同
                    continue;
                }
                else { //如果首次出现的位置不同，说明无法同构
                    result = false;
                    break;
                }
            }
            else if (ums.find(s[i]) == ums.end() &&
                umt.find(t[i]) == umt.end()) { // 如果没有被记录过
                ums[s[i]] = umt[t[i]] = i; //记录首次位置
            }
            else { // 如果只有其中一个有首次位置，说明不匹配
                result = false;
                break;
            }
        }
        return result;
    }
};
