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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (letters[mid] <= target)
            {
                if (mid < letters.size() - 1 && letters[mid + 1] > target)
                {
                    return letters[mid + 1];

                }
                left = mid + 1;
            }else {
                if (0< mid && letters[mid - 1] < target)
                {
                    return letters[mid];
                }
                right = mid - 1;
            }
        }
        return letters[0];
    }
};

