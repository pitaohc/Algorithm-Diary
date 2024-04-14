#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <array>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> buckets;
        for (const char& ch : magazine) {
            ++buckets[ch - 'a'];
        }
        for (const char& ch : ransomNote) {
            --buckets[ch - 'a'];
        }
        for (const int& count : buckets) {
            if (count < 0) {
                return false;
            }
        }
        return true;
    }
};
