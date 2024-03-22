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
    int hIndex(vector<int>& citations) {

        int left = 0, right = citations.size();
        int mid = 0, cnt = 0;
#ifdef _DEBUG
        int round = 0;
#endif // _DEBUG

        while (left < right) {


            mid = left + ((right - left + 1) >> 1); // +1 是为了避免出现死循环
            cnt = 0;
            for (const auto cit : citations) {
                cnt += cit >= mid;
            }
#ifdef _DEBUG
            fmt::print("round {}: mid = {}, cnt = {}\n", round++, mid, cnt);
#endif // _DEBUG
            if (cnt >= mid) { // 当出现 left = mid = cnt 时，会出现死循环，因此mid计算时需要避免死循环
                left = mid;

            }
            else {
                right = mid - 1; //因为mid不满足要求
            }
        }

        return left;
    }
};

